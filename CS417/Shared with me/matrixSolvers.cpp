/*
 * matrixSolvers.cpp
 *
 *  Modified version:
 *      - Renamed from directSolvers.cpp to matrixSolvers.cpp
 *      - Class name changed from directSolvers to matrixSolvers
 *      - Intermediate print statements have been removed.
 *      - Iteration counts have been added for each significant loop.
 *      - Matrices are printed only at the very end.
 */

#include "matrixSolvers.h"
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

/**
 * Finds the pivot row number in a given matrix.
 *
 * @param A        const reference to a diagonally dominant matrix.
 * @param column   column in which we are going to find the pivot row.
 * @return int     the row with the largest value to be used as the pivot column.
 */
int matrixSolvers::findPivot(const matrix& A, int column)
{
    int pivotRow = column;
    double largest = std::abs(A[column][column]);

    for (int i = column + 1; i < A.numrows(); ++i)
    {
        if (std::abs(A[i][column]) > largest)
        {
            pivotRow = i;
            largest = std::abs(A[i][column]);
        }
    }
    return pivotRow;
}

/**
 * Backsolve for matrix in Upper Echelon form.
 *
 * @param A   reference to *augmented* matrix A, has already been converted to REF or RREF.
 * @param x   reference to vector where the solution variables will be stored.
 */
void matrixSolvers::backsolve(matrix& A, matrix& x)
{
    int bCol = A.numcols() - 1;
    int n = A.numrows() - 1;

    // Initialize x if it's not already initialized correctly
    if (x.numrows() != A.numrows() || x.numcols() != 1)
    {
        x = matrix(A.numrows(), 1);
    }

    // Solve for x_n
    x[n][0] = (A[n][bCol] / A[n][n]);

    // Backsolve from n-1 to 0
    for (int i = n - 1; i >= 0; --i)
    {
        double sum = 0.0;
        for (int j = i + 1; j <= n; ++j)
        {
            sum += (A[i][j] * x[j][0]);
        }
        // A_ii * x_i = b_i - sum
        // Divide RHS by A_ii
        x[i][0] = ((A[i][bCol] - sum) / A[i][i]);
    }
}

/**
 * Backsolve for matrix in Upper Echelon form for LU decomposition.
 *
 * @param U   reference to Upper triangular matrix U where A = LU.
 * @param x   reference to the original x vector which will be solved in this sweep.
 * @param y   const reference to intermediate vector y.
 */
void matrixSolvers::LUbacksolve(matrix& U, matrix& x, const matrix& y)
{
    int n = U.numrows() - 1;

    // Initialize x if it's not already initialized correctly
    if (x.numrows() != U.numrows() || x.numcols() != 1)
    {
        x = matrix(U.numrows(), 1);
    }

    // Solve for x_n
    x[n][0] = y[n][0];

    // Backsolve from n-1 to 0
    for (int i = n - 1; i >= 0; --i)
    {
        double sum = 0.0;
        for (int j = i + 1; j <= n; ++j)
        {
            sum += (U[i][j] * x[j][0]);
        }
        // No division by U_ii since U has 1s on its diagonal
        x[i][0] = (y[i][0] - sum);
    }
}

/**
 * Forward sweep for LU solver.
 *
 * @param L   reference to Lower triangular matrix for LU solver, where A = LU.
 * @param y   reference to y.
 * @param b   const reference to the vector b.
 */
void matrixSolvers::forwardSolve(matrix& L, matrix& y, const matrix& b)
{
    int n = L.numrows() - 1;

    // Initialize y if it's not already initialized correctly
    if (y.numrows() != L.numrows() || y.numcols() != 1)
    {
        y = matrix(L.numrows(), 1);
    }

    // Solve for y_0
    y[0][0] = (b[0][0] / L[0][0]);

    // Sweep from row 1 to row n
    for (int i = 1; i <= n; ++i)
    {
        double sum = 0.0;
        for (int j = 0; j < i; ++j)
        {
            sum += (L[i][j] * y[j][0]);
        }
        // L_ii * y_i = b_i - sum
        y[i][0] = ((b[i][0] - sum) / L[i][i]);
    }
}

/**
 * Gaussian Elimination direct solver.
 *
 * @param A   reference - square diagonally dominant matrix.
 * @param x   reference parameter where we will store our solution.
 * @param b   const reference - RHS, size A.numrows() x 1.
 */
void matrixSolvers::gaussianElimination(matrix& A, matrix& x, const matrix& b)
{
    // Counters for iterations
    int totalEliminationSteps = 0;

    // Check matrix dimensions
    if (!(A.numcols() == A.numrows()) || !(A.numcols() == b.numrows()))
    {
        throw std::logic_error("Matrix size mismatch");
    }

    // Initialize x if it's not already initialized correctly
    if (x.numrows() != A.numrows() || x.numcols() != 1)
    {
        x = matrix(A.numrows(), 1);
    }

    A.augment(b);

    // Performing elimination
    for (int i = 0; i < A.numrows(); ++i)
    {
        // Find the row with the largest element in column i
        int pivot = findPivot(A, i);

        // Swap rows if pivot is not the current row
        if (pivot != i)
        {
            A.swapRows(pivot, i);
        }

        // Normalize pivot row to have a leading 1
        if (A[i][i] != 1.0)
        {
            double inverseA_ii = (1.0 / A[i][i]);
            A.multiplyRow(i, inverseA_ii);
        }

        // Eliminate entries below the pivot
        for (int j = i + 1; j < A.numrows(); ++j)
        {
            totalEliminationSteps++; // Counting elimination steps

            std::vector<double> savedPivotRow = A[i];

            // Scale pivot row
            double scaler = (-1.0 * (A[j][i] / A[i][i]));
            A.multiplyRow(i, scaler);
            // Add scaled pivot row to current row
            A.addRows(i, j, j);

            // Restore pivot row
            A.swapRows(savedPivotRow, i);
        }
    }

    backsolve(A, x);

    // Output iteration count
    std::cout << "Total elimination steps in Gaussian Elimination: " << totalEliminationSteps << std::endl;
}

/**
 * Performs LU decomposition on a square matrix.
 *
 * @param A   reference to square matrix A to be decomposed into Upper and Lower matrices.
 */
void matrixSolvers::decomp(matrix& A)
{
    int n = A.numrows() - 1;

    // Counters for iterations
    int totalLUComputations = 0;

    double temp = A[0][0]; // Saving because we temporarily overwrite it.

    // First row of U
    A.multiplyRow(0, (1 / temp));

    // Restore A[0][0]
    A[0][0] = temp;

    for (int j = 1; j < n; ++j)
    {
        // Compute entries of L
        for (int i = j; i <= n; ++i)
        {
            totalLUComputations++; // Counting computations for L
            double sumLUterms = 0.0;
            for (int k = 0; k < j; ++k)
            {
                sumLUterms += (A[i][k] * A[k][j]);
            }
            A[i][j] = (A[i][j] - sumLUterms);
        }

        // Compute entries of U
        for (int k = (j + 1); k <= n; ++k)
        {
            totalLUComputations++; // Counting computations for U
            double sumLUterms = 0.0;
            for (int i = 0; i < j; ++i)
            {
                sumLUterms += (A[j][i] * A[i][k]);
            }
            A[j][k] = ((A[j][k] - sumLUterms) / A[j][j]);
        }
    }

    // Compute A[n][n]
    double sumLUterms = 0.0;
    for (int k = 0; k < n; ++k)
    {
        sumLUterms += A[n][k] * A[k][n];
    }
    A[n][n] = (A[n][n] - sumLUterms);

    // Output iteration count
    std::cout << "Total computations in LU decomposition: " << totalLUComputations << std::endl;
}

/**
 * LU decomposition direct solver.
 *
 * @param A   reference - square diagonally dominant matrix.
 * @param x   reference parameter where we will store our solution.
 * @param b   const reference - RHS, size A.numrows() x 1.
 */
void matrixSolvers::LUdecomposition(matrix& A, matrix& x, const matrix& b)
{
    // Check matrix dimensions
    if (!(A.numcols() == A.numrows()) || !(A.numcols() == b.numrows()))
    {
        throw std::logic_error("Matrix size mismatch");
    }

    // Initialize x if it's not already initialized correctly
    if (x.numrows() != A.numrows() || x.numcols() != 1)
    {
        x = matrix(A.numrows(), 1);
    }

    // Perform LU decomposition (A is overwritten with L and U)
    decomp(A);

    // Initialize intermediate vector y
    matrix y(A.numrows(), 1);

    // Forward solve Ly = b
    forwardSolve(A, y, b);

    // Backsolve Ux = y
    LUbacksolve(A, x, y);
}