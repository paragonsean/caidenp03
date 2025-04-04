#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

int main() {
    int n;
    ifstream file("midterm1.txt");
    file.open("midterm1.txt");
    cout << "Enter the number of equations: ";
    //if (file.is_open())
    file >> n;
    cout << n;

    vector<vector<float>> A(n, vector<float>(n + 1));

    cout << "Enter the augmented matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n + 1; ++j) {
            file >> A[i][j];
        }
    }

    // Gaussian elimination
    for (int i = 0; i < n; ++i) {
        // Partial pivoting
        int maxRow = i;
        for (int j = i + 1; j < n; ++j) {
            if (abs(A[j][i]) > abs(A[maxRow][i])) {
                maxRow = j;
            }
        }
        if (maxRow != i) {
            swap(A[i], A[maxRow]);
        }

        // Forward elimination
        for (int j = i + 1; j < n; ++j) {
            float factor = A[j][i] / A[i][i];
            for (int k = i; k < n + 1; ++k) {
                A[j][k] -= factor * A[i][k];
            }
        }
    }

    // Back substitution
    vector<float> x(n);
    for (int i = n - 1; i >= 0; --i) {
        x[i] = A[i][n];
        for (int j = i + 1; j < n; ++j) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }

    // Print the solution
    cout << "Solution:\n";
    for (int i = 0; i < n; ++i) {
        cout << "x[" << i << "] = " << x[i] << endl;
    }
    file.close();
    return 0;
}
