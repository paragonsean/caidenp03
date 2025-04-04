#include "Matrix.h"
#include "matrixGenerator.h"
#include "matrixSolvers.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>   // For measuring time
#include <iomanip> // For formatting output with precision
#include <cmath>   // For sqrt function
#include <limits>
using namespace std;

typedef Matrix matrix;

enum solvers
{
    cancel = -1,
    GE = 1,
    LU = 2
};

// Function to print any matrix with formatting
void printMatrix(const matrix &M, const string &name = "Matrix")
{
    std::cout << name << " (" << M.numrows() << "x" << M.numcols() << "):\n";
    for (int i = 0; i < M.numrows(); ++i)
    {
        for (int j = 0; j < M.numcols(); ++j)
        {
            std::cout << std::setw(10) << std::setprecision(10) << M[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}

// Remove local writeSolutionToFile and writeMatrixToFile functions
// They are now replaced by MatrixGenerator methods

int printSolverOptions(istream &input)
{
    std::cout << "1 - Gaussian Elimination" << std::endl;
    std::cout << "2 - LU decomposition" << std::endl;
    std::cout << "0 - Cancel" << std::endl;
    std::cout << "Enter selection: " << std::endl;

    int selection;
    while (!(input >> selection) || ((selection < 0) || (selection > 2)))
    {
        input.clear();
        input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, try again: \n";
    }
    input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return selection;
}

// Modified to read both A and b from the file
void loadDefaultAB(matrix &A, matrix &b)
{
    try
    {
        MatrixGenerator::readMatrixFromFile(A, b, "matdata.txt");
        std::cout << "Matrix A and vector b loaded from \"matdata.txt\"\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error loading matrix A and vector b: " << e.what() << "\n";
    }
}

void printSolution(const matrix &x, const string &name = "x")
{
    std::cout << "Solution " << name << " is: \n";
    printMatrix(x, name);
}

double computeErrorNorm(const matrix &x_computed, const matrix &x_original)
{
    int N = x_original.numrows();
    double sumSquaredDifferences = 0.0;

    for (int i = 0; i < N; ++i)
    {
        double difference = x_computed[i][0] - x_original[i][0];
        sumSquaredDifferences += difference * difference;
    }

    double errorNorm = sqrt(sumSquaredDifferences) / N;

    return errorNorm;
}

int executeSolver(istream &input, int selection, const matrix &A_original, const matrix &b, matrix &x_computed)
{
    if (A_original.numcols() != A_original.numrows())
    {
        cout << "Error: Matrix A must be square.\n";
        return -1;
    }

    int N = A_original.numrows();

    // Generate the original x vector
    matrix x_original(N, 1);
    for (int i = 0; i < N; ++i)
    {
        x_original[i][0] = static_cast<double>(i + 1);
    }

    // Create a copy of A to work on, since A is modified during solving
    matrix A = A_original;

    // Initialize the solution vector 'x_computed' with the correct size
    x_computed = matrix(N, 1);

    clock_t t_0, t_end;
    t_0 = clock(); // Start timing

    try
    {
        switch (selection)
        {
        case LU:
            matrixSolvers::LUdecomposition(A, x_computed, b);
            t_end = clock(); // End timing
            std::cout << "LU decomposition completed.\n";

            if (A.numcols() > 100)
            {
                cout << "Matrix A is too large to print. They will be written to files instead.\n";
                MatrixGenerator::writeMatrixToFile(A, "modified_matrix_A.txt");
                MatrixGenerator::writeOutSolution(b, "mat_solution.txt");
            }
            else
            {
                printMatrix(A, "Modified Matrix A after LU Decomposition");
                printMatrix(b, "Vector b");
            }
            printSolution(x_computed, "Computed x");
            MatrixGenerator::writeOutSolution(x_computed, "mat_solution.txt");
            break;
        case GE:
            matrixSolvers::gaussianElimination(A, x_computed, b);
            t_end = clock(); // End timing
            std::cout << "Gaussian Elimination completed.\n";

            if (A.numcols() > 100)
            {
                cout << "Matrix A is too large to print. They will be written to files instead.\n";
                MatrixGenerator::writeMatrixToFile(A, "modified_matrix_A.txt");
                MatrixGenerator::writeOutSolution(b, "mat_solution.txt");
            }
            else
            {
                printMatrix(A, "Modified Matrix A after Gaussian Elimination");
                printMatrix(b, "Vector b");
            }
            printSolution(x_computed, "Computed x");
            MatrixGenerator::writeOutSolution(x_computed, "mat_solution.txt");
            break;
        default:
            return -1;
        }
    }
    catch (const std::exception &e)
    {
        cerr << "Error during solving: " << e.what() << endl;
        return -1;
    }

    std::cout << "Calculations took "
              << ((float)(t_end - t_0)) / CLOCKS_PER_SEC << " seconds.\n\n";

    // Compute the error norm
    double errorNorm = computeErrorNorm(x_computed, x_original);
    std::cout << "Error Norm: " << errorNorm << std::endl;

    if (errorNorm < 1e-8)
    {
        std::cout << "Solution is acceptable (Error Norm < 1e-8).\n";
    }
    else
    {
        std::cout << "Solution may not be accurate enough (Error Norm >= 1e-8).\n";
    }

    return 0;
}

solvers solverMenu(istream &input)
{
    int menuSelection = printSolverOptions(input);
    switch (menuSelection)
    {
    case LU:
        return LU;
    case GE:
        return GE;
    case 0:
    default:
        return cancel;
    }
}

int main()
{
    matrix A_original, b, x_computed;
    int menuSelection = -1;
    solvers solverSelection = cancel;

    while (menuSelection != 0)
    {
        cout << "1 - Generate a random matrix A and vector b, and write to file (matdata.txt).\n";
        cout << "2 - Load matrix A and vector b from file (matdata.txt).\n";
        cout << "3 - Use a solver to solve for x.\n";
        cout << "4 - Print most recent computed solution x.\n";
        cout << "5 - Print matrix A.\n";
        cout << "6 - Write matrix A to file (matrix_A.txt).\n";
        cout << "0 - Exit.\n";
        cout << "Enter selection: \n";

        while (!(cin >> menuSelection) || (menuSelection < 0 || menuSelection > 6))
        {
            cin.clear();  // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore bad input
            cout << "Invalid input, please enter a number between 0 and 6: \n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (menuSelection)
        {
        case 1:
            // Generate random matrix A and vector b
            MatrixGenerator::generateRandomMatrixAndWriteToFile("matdata.txt");
            break;
        case 2:
            // Load matrix A and vector b from file
            loadDefaultAB(A_original, b);
            break;
        case 3:
            if (A_original.numrows() == 0)
            {
                cout << "Load matrix A and vector b from file before running solvers!\n";
                break;
            }
            solverSelection = solverMenu(cin);
            if (solverSelection != cancel)
                executeSolver(cin, solverSelection, A_original, b, x_computed);
            break;
        case 4:
            if (x_computed.numrows() == 0)
            {
                cout << "No computed solution to display. Please run a solver first.\n";
                break;
            }
            printSolution(x_computed, "Computed x");
            break;
        case 5:
            if (A_original.numrows() == 0)
            {
                cout << "Matrix A is empty. Load it first.\n";
                break;
            }
            printMatrix(A_original, "Original Matrix A"); // Print original matrix A
            break;
        case 6:
            if (A_original.numrows() == 0)
            {
                cout << "Matrix A is empty. Load it first.\n";
                break;
            }
            // Write matrix A to file using MatrixGenerator
            MatrixGenerator::writeMatrixToFile(A_original, "matrix_A.txt");
            break;
        case 0:
            break;
        default:
            cout << "Invalid selection, try again.\n";
            break;
        }
    }

    return 0;
}