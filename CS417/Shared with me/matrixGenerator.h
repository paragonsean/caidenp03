#ifndef MATRIXGENERATOR_H
#define MATRIXGENERATOR_H

#include "Matrix.h"
#include <string>
#include <iostream>

typedef Matrix matrix;

class MatrixGenerator {
public:
    /**
     * Asks the user for the matrix size (m x n).
     *
     * @param input The input stream to read from.
     * @param m Reference to store the number of rows.
     * @param n Reference to store the number of columns.
     */
    static void askForMatrixSize(std::istream& input, int& m, int& n);

    /**
     * Reads matrix A and vector b from a file.
     *
     * @param A Reference to the matrix A to be filled.
     * @param b Reference to the vector b to be filled.
     * @param filename The name of the file to read from.
     */
    static void readMatrixFromFile(matrix& A, matrix& b, const std::string& filename);

    /**
     * Reads only matrix A from a file (without vector b).
     *
     * @param A Reference to the matrix A to be filled.
     * @param filename The name of the file to read from.
     */
    static void readMatrixFromFile(matrix& A, const std::string& filename);

    /**
     * Writes the solution vector x to a file.
     *
     * @param x The solution vector to write.
     * @param filename The name of the file to write to.
     */
    static void writeOutSolution(const matrix& x, const std::string& filename);

    /**
     * Writes matrix A and vector b to a file.
     *
     * @param A The matrix A to write.
     * @param b The vector b to write.
     * @param filename The name of the file to write to.
     */
    static void writeMatrixToFile(const matrix& A, const matrix& b, const std::string& filename);

    /**
     * Writes only matrix A to a file (without vector b).
     *
     * @param A The matrix A to write.
     * @param filename The name of the file to write to.
     */
    static void writeMatrixToFile(const matrix& A, const std::string& filename);

    /**
     * Generates a random diagonally dominant matrix A, a solution vector x,
     * computes b = A * x, and writes A and b to a file.
     *
     * @param filename The name of the file to write the matrix and vector.
     */
    static void generateRandomMatrixAndWriteToFile(const std::string& filename);
};

#endif // MATRIXGENERATOR_H