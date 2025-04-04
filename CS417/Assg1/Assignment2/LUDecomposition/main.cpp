#include <iostream>
#include <iomanip>

using namespace std;
//function to call inside main that does the calculation
void LUDecomposition(double** A, int n) {
    double** L = new double*[n];
    double** U = new double*[n];
//make the pointer of pointers
    for (int i = 0; i < n; ++i) {
        L[i] = new double[n];
        U[i] = new double[n];
    }
//n will be the size of the matrix, iterate until n has been fully generated
    for (int i = 0; i < n; ++i) {
        // Initialize L matrix
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                L[i][j] = 1;
            } else {
                L[i][j] = 0;
            }
        }

        // Calculate U and L matrices
        for (int j = 0; j < n; ++j) {
            if (i <= j) {
                U[i][j] = A[i][j];
                for (int k = 0; k < i; ++k) {
                    U[i][j] -= L[i][k] * U[k][j];
                }
            } else {
                L[i][j] = A[i][j];
                for (int k = 0; k < j; ++k) {
                    L[i][j] -= L[i][k] * U[k][j];
                }
                L[i][j] /= U[j][j];
            }
        }
    }

    // Print L matrix (0s on the bottom)
    cout << "L matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(8) << L[i][j];
        }
        cout << endl;
    }

    // Print U matrix (0s on the top)
    cout << "U matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(8) << U[i][j];
        }
        cout << endl;
    }

    // Deallocate memory
    for (int i = 0; i < n; ++i) {
        delete[] L[i];
        delete[] U[i];
    }
    delete[] L;
    delete[] U;
}

int main() {
    int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;

    double** A = new double*[n];
    for (int i = 0; i < n; ++i) {
        A[i] = new double[n];
    }

    cout << "Enter the matrix elements:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    LUDecomposition(A, n);

    // Deallocate memory
    for (int i = 0; i < n; ++i) {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}
