#include <iostream>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

int main() {
    int n = 500;

    // Allocate 2D dynamic arrays (n x n)
    int** A = new int*[n];
    int** B = new int*[n];
    int** C = new int*[n];
    for (int i = 0; i < n; i++) {
        A[i] = new int[n];
        B[i] = new int[n];
        C[i] = new int[n];
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
            C[i][j] = 0;
        }
    }

    // Time standard triple-nested loop Matrix Multiplication
    auto start = high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    auto stop = high_resolution_clock::now();

    double ms = duration_cast<microseconds>(stop - start).count() / 1000.0;

    // Estimate space: 3 matrices of size n x n integers (4 bytes each)
    long long spaceBytes = 3 * (long long)n * n * sizeof(int);

    cout << "n = " << n
         << " | Time: " << ms << " ms"
         << " | Approx Matrix Space: " << spaceBytes / 1024.0 << " KB" << endl;

    // Clean up heap allocation
    for (int i = 0; i < n; i++) {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}