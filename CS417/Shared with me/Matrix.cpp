#include "Matrix.h"
#include <iomanip>  // For std::setprecision and std::setw
#include <vector>

Matrix::Matrix() {}

Matrix::Matrix(int rows, int cols) : array(rows) {
    for (auto& row : array) {
        row.resize(cols);
    }
}

Matrix::Matrix(int rows, int cols, double defaultValue) : array(rows) {
    for (auto& row : array) {
        row.assign(cols, defaultValue);
    }
}

// Non-const version
std::vector<double>& Matrix::operator[](int row) {
    if (row < 0 || row >= array.size()) {
        std::cerr << "Error: Row index " << row << " out of range (size: " << array.size() << ")" << std::endl;
        throw std::out_of_range("Matrix index out of range");
    }
    return array[row];
}

// Const version
const std::vector<double>& Matrix::operator[](int row) const {
    if (row < 0 || row >= array.size()) {
        std::cerr << "Error: Row index " << row << " out of range (size: " << array.size() << ")" << std::endl;
        throw std::out_of_range("Matrix index out of range");
    }
    return array[row];
}

Matrix::Matrix(const std::vector<std::vector<double>>& v) : array(v) {}

Matrix::Matrix(const std::vector<std::vector<double>>& v, double defaultValue) : array(v) {}

Matrix::Matrix(const std::vector<double>& v, double defaultValue) {
    array.push_back(v);
}

Matrix::Matrix(const Matrix& m) : array(m.array) {}

Matrix::~Matrix() {
    // No need to manually clear the array; std::vector handles its own memory management.
}

bool Matrix::operator==(const Matrix& m) const {
    return array == m.array;
}

bool Matrix::operator!=(const Matrix& m) const {
    return !(*this == m);
}

Matrix& Matrix::operator=(const Matrix& right) {
    if (this != &right) { // Correct self-assignment check
        array = right.array;
    }
    return *this;
}

Matrix& Matrix::multiplyRow(int rowNum, double scaler) {
    if (rowNum < 0 || rowNum >= array.size()) {
        throw std::out_of_range("parameters given are outside of matrix boundaries");
    }

    std::vector<double>& row = array.at(rowNum);
    for (int i = 0; i < row.size(); ++i) {
        row[i] = scaler * row[i];
    }
    return *this;
}

Matrix& Matrix::addRows(int rowOne, int rowTwo, int destinationRow) {
    if (rowOne < 0 || rowOne >= array.size() || rowTwo < 0 || rowTwo >= array.size() || destinationRow < 0 || destinationRow >= array.size()) {
        throw std::out_of_range("parameters given are outside of matrix boundaries");
    }

    std::vector<double>& row1 = array.at(rowOne);
    std::vector<double>& row2 = array.at(rowTwo);
    std::vector<double>& writeRow = array.at(destinationRow);

    for (int i = 0; i < row1.size(); ++i) {
        writeRow[i] = row1[i] + row2[i];
    }
    return *this;
}

Matrix& Matrix::swapRows(std::vector<double>& swapRow, int rowOne) {
    if (rowOne < 0 || rowOne >= array.size()) {
        throw std::out_of_range("parameters given are outside of matrix boundaries");
    }

    array.at(rowOne).swap(swapRow);
    return *this;
}

void Matrix::eye() {
    if (array.size() != array.at(0).size()) {
        throw std::logic_error("Matrix size mismatch");
    }

    int tempSize = array.size();
    array.clear();
    array.resize(tempSize);

    for (int i = 0; i < array.size(); ++i) {
        array.at(i).assign(tempSize, 0.0);
        (*this)[i][i] = 1.0;
    }
}

void Matrix::eye(int rows, int cols) {
    array.clear();
    array.resize(rows);

    for (int i = 0; i < array.size(); ++i) {
        array.at(i).assign(cols, 0.0);
        (*this)[i][i] = 1.0;
    }
}

// Only keep one augment function to avoid duplicate errors
Matrix& Matrix::augment(const Matrix& right) {
    if (array.size() != right.numrows() || right.numcols() != 1) {
        throw std::logic_error("Matrix size mismatch");
    }

    for (int i = 0; i < array.size(); ++i) {
        array.at(i).push_back(right[i][0]);
    }

    return *this;
}

// Only keep one swapRows function to avoid duplicate errors
Matrix& Matrix::swapRows(int rowOne, int rowTwo) {
    if (rowOne < 0 || rowOne >= array.size() || rowTwo < 0 || rowTwo >= array.size()) {
        throw std::out_of_range("parameters given are outside of matrix boundaries");
    }

    array.at(rowOne).swap(array.at(rowTwo));
    return *this;
}

Matrix operator*(const Matrix& left, const Matrix& right) {
    if (left.numcols() != right.numrows()) {
        throw std::logic_error("Matrix size mismatch");
    }
    Matrix solution(left.numrows(), right.numcols());
    for (int i = 0; i < left.numrows(); ++i) {
        for (int j = 0; j < right.numcols(); ++j) {
            double tempValue = 0.0;
            for (int k = 0; k < right.numrows(); ++k) {
                tempValue += (left[i][k]) * (right[k][j]);
            }
            solution[i][j] = tempValue;
        }
    }
    return solution;
}

std::ostream& operator<<(std::ostream& out, const Matrix& m) {
    for (int j = 0; j < m.numrows(); ++j) {
        for (int i = 0; i < m.numcols(); ++i) {
            if (i > 0)
                out << ' ';
            out << std::setprecision(18) << std::setw(21);
            out << m[j][i];
        }
        out << "\n";
    }
    return out;
}

double relError(const Matrix& est, const Matrix& actual) {
    if (!(est.numrows() == actual.numrows()) || !(est.numcols() == actual.numcols())) {
        throw std::logic_error("Matrix size mismatch");
    }

    double diffSumOfSquares = 0.0;
    double actualSumOfSquares = 0.0;

    for (int i = 0; i < est.numrows(); ++i) {
        for (int j = 0; j < est.numcols(); ++j) {
            double diffSquared = pow((est[i][j] - actual[i][j]), 2.0);
            double actualSquared = pow(actual[i][j], 2.0);

            diffSumOfSquares += diffSquared;
            actualSumOfSquares += actualSquared;
        }
    }

    double err = (sqrt(diffSumOfSquares) / sqrt(actualSumOfSquares));
    return err;
}