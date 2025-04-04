#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cmath>

class Matrix
{
public:
    Matrix(int rows, int cols);
    Matrix(const std::vector<std::vector<double>> &v);

    Matrix();
    Matrix(int rows, int cols, double defaultValue);
    Matrix(const std::vector<std::vector<double>> &v, double defaultValue);  // Consider using defaultValue
    Matrix(const std::vector<double> &v, double defaultValue);
    Matrix(const Matrix&);

    ~Matrix();

    bool operator==(const Matrix& m) const;
    bool operator!=(const Matrix& m) const;

    Matrix& operator=(const Matrix&);

    void eye();
    void eye(int rows, int cols);
    Matrix& augment(const Matrix& right);
    Matrix& swapRows(int rowOne, int rowTwo);
    Matrix& swapRows(std::vector<double>& swapRow, int rowOne);
    Matrix& multiplyRow(int rowNum, double scaler);
    Matrix& addRows(int rowOne, int rowTwo, int destinationRow);
    Matrix& addRows(std::vector<double>& rowOne, int rowTwo, int destinationRow);

    const std::vector<double> & operator[](int row) const;
    std::vector<double> & operator[](int row);

    inline int numrows() const {
        return array.size();
    }

    inline int numcols() const {
        if (numrows() == 0) {
            return 0;
        } else {
            return array.at(0).size();
        }
    }

private:
    std::vector<std::vector<double>> array;
};

// Global operator overloads
std::ostream& operator<<(std::ostream& out, const Matrix& m);
Matrix operator*(const Matrix& left, const Matrix& right);
Matrix operator*(double scaler, const Matrix& m);
Matrix operator*(const Matrix& m, double scaler);
Matrix operator+(const Matrix& left, const Matrix& right);
Matrix operator-(const Matrix& left, const Matrix& right);
double relError(const Matrix& est, const Matrix& actual);

#endif
