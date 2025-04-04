#include "matrixGenerator.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <stdexcept>
#include <limits>
#include <random>
#include <ctime>


typedef Matrix matrix;
void MatrixGenerator::generateRandomMatrixAndWriteToFile(const std::string& filename)
{
    int n;
    std::cout << "Enter the size of the matrix (n): ";
    while (!(std::cin >> n) || n <= 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, please enter a positive integer: ";
    }

    // Allocate matrices and vectors
    matrix A(n, n);
    matrix x(n, 1);
    matrix b(n, 1);

    // Initialize random number generator
    std::default_random_engine gen(static_cast<unsigned>(time(nullptr)));
    std::normal_distribution<double> ndist(0.0, 50.0);

    // Initialize x with values from 1 to n
    for (int i = 0; i < n; ++i)
    {
        x[i][0] = static_cast<double>(i + 1);
    }

    // Generate random matrix A and ensure diagonal dominance
    for (int row = 0; row < n; ++row)
    {
        double s = 0.0;
        for (int col = 0; col < n; ++col)
        {
            double r = ndist(gen);
            s += std::abs(r);
            A[row][col] = r;
        }
        // Adjust diagonal element to ensure diagonal dominance
        A[row][row] = s;
    }

    // Compute b = A * x
    for (int i = 0; i < n; ++i)
    {
        double sum = 0.0;
        for (int col = 0; col < n; ++col)
        {
            sum += A[i][col] * x[col][0];
        }
        b[i][0] = sum;
    }

    // Print A to the console
    std::cout << "\nMatrix A:\n";
    for (int row = 0; row < n; ++row)
    {
        for (int col = 0; col < n; ++col)
        {
            std::cout << "A[" << row << "][" << col << "] = " << A[row][col] << "\n";
        }
    }

    // Print solution vector x
    std::cout << "\nSolution vector x:\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << "x[" << i << "] = " << x[i][0] << "\n";
    }

    // Print right-hand side vector b
    std::cout << "\nRight-hand side vector b:\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << "b[" << i << "] = " << b[i][0] << "\n";
    }

    // Write n, A, and b to the file
    std::ofstream fout(filename);
    if (!fout)
    {
        std::cerr << "Error opening file " << filename << " for writing.\n";
        return;
    }

    fout << n << "\n";
    // Write matrix A
    for (int row = 0; row < n; ++row)
    {
        for (int col = 0; col < n; ++col)
        {
            fout << std::fixed << std::setprecision(6) << A[row][col] << " ";
        }
        fout << "\n";
    }
    // Write vector b
    for (int i = 0; i < n; ++i)
    {
        fout << std::fixed << std::setprecision(6) << b[i][0] << " ";
    }
    fout << "\n";

    fout.close();
    std::cout << "\nMatrix A and vector b have been written to " << filename << "\n";
}
// Ask for matrix size (m x n)
void MatrixGenerator::askForMatrixSize(std::istream& input, int& m, int& n)
{
    std::cout << "Enter desired size (m x n) for matrix A \n-- in integers, separated by a space: \n";
    while (!(input >> m >> n))
    {
        input.clear();
        input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, try again: \n";
    }
    input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Read matrix A and vector b from file
void MatrixGenerator::readMatrixFromFile(matrix& A, matrix& b, const std::string& filename)
{
    std::ifstream input(filename);

    if (!input) {
        std::cerr << "Failed to open the file: " << filename << "\n";
        throw std::runtime_error("File not found");
    }

    int n = 0;  // Read the size of the matrix (n x n)
    input >> n;

    // Initialize matrix A as n x n and vector b as n x 1
    A = matrix(n, n);
    b = matrix(n, 1);

    double tempValue = 0.0;

    // Read n * n values for matrix A
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!(input >> tempValue)) {
                throw std::runtime_error("Error reading matrix A from file.");
            }
            A[i][j] = tempValue;
        }
    }

    // Read n values for vector b
    for (int i = 0; i < n; ++i) {
        if (!(input >> tempValue)) {
            throw std::runtime_error("Error reading vector b from file.");
        }
        b[i][0] = tempValue;
    }

    input.close();
}

// Read only matrix A from file (without b)
void MatrixGenerator::readMatrixFromFile(matrix& A, const std::string& filename)
{
    std::ifstream input(filename);

    if (!input) {
        std::cerr << "Failed to open the file: " << filename << "\n";
        throw std::runtime_error("File not found");
    }

    int n = 0;  // Read the size of the matrix (n x n)
    input >> n;

    // Initialize matrix A as n x n
    A = matrix(n, n);

    double tempValue = 0.0;

    // Read n * n values for matrix A
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!(input >> tempValue)) {
                throw std::runtime_error("Error reading matrix A from file.");
            }
            A[i][j] = tempValue;
        }
    }

    input.close();
}

// Write the solution vector x to a file
void MatrixGenerator::writeOutSolution(const matrix& x, const std::string& filename)
{
    int n = x.numrows();
    int sqrtN = static_cast<int>(sqrt(n));

    std::ofstream output(filename);

    if (!output)
    {
        std::cerr << "Error opening file " << filename << " for writing.\n";
        return;
    }

    // Set precision for floating-point numbers
    output << std::fixed << std::setprecision(10);

    // Check if n is a perfect square
    if (sqrtN * sqrtN == n)
    {
  

        for (int i = 0; i < sqrtN; ++i)
        {
            for (int j = 0; j < sqrtN; ++j)
            {
                int index = i * sqrtN + j;
                output << std::setw(15) << x[index][0] << ",";
            }
            output << "\n";
        }
    }
    else
    {
        output << "Solution vector is not a perfect square. Writing as a column vector.\n";
        output << "Solution vector (length: " << n << "):\n";

        for (int i = 0; i < n; ++i)
        {
            output << std::setw(15) << x[i][0] << "\n";
        }
    }

    output.close();
    std::cout << "Solution written to " << filename << "\n";
}
// Write matrix A and vector b to file
void MatrixGenerator::writeMatrixToFile(const matrix& A, const matrix& b, const std::string& filename)
{
    std::ofstream output(filename);

    if (!output) {
        std::cerr << "Error opening file " << filename << " for writing.\n";
        return;
    }

    if (A.numrows() != b.numrows() || b.numcols() != 1) {
        throw std::logic_error("Matrix sizes are incompatible for file format");
    }

    int n = A.numrows();

    // Write the size of the matrix
    output << n << "\n";

    // Write matrix A and vector b
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < A.numcols(); ++j)
        {
            output << std::fixed << std::setprecision(8) << A[i][j] << " ";
        }
        output << std::fixed << std::setprecision(8) << b[i][0] << "\n";
    }

    output.close();
    std::cout << "Matrix A and vector b written to " << filename << "\n";
}

// Write only matrix A to file (without b)
void MatrixGenerator::writeMatrixToFile(const matrix& A, const std::string& filename)
{
    std::ofstream output(filename);

    if (!output) {
        std::cerr << "Error opening file " << filename << " for writing.\n";
        return;
    }

    int n = A.numrows();

    // Write the size of the matrix
    output << n << "\n";

    // Write matrix A
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < A.numcols(); ++j)
        {
            output << std::fixed << std::setprecision(6) << A[i][j] << " ";
        }
        output << "\n";
    }

    output.close();
    std::cout << "Matrix A written to " << filename << "\n";
}