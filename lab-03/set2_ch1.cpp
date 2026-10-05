#include <iostream>
#include <algorithm>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

void bubbleSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n = 100000; // Test range: 1000, 5000, 10000, 20000, 50000, 100000

    // Create primary random array and copies for fair comparison
    int* copy1 = new int[n];
    int* copy2 = new int[n];

    for (int i = 0; i < n; i++) {
        int val = rand();
        copy1[i] = val;
        copy2[i] = val;
    }

    // 1. Time Bubble Sort (O(n^2))
    auto start = high_resolution_clock::now();
    bubbleSort(copy1, n);
    auto stop = high_resolution_clock::now();
    double bubbleMs = duration_cast<microseconds>(stop - start).count() / 1000.0;

    // 2. Time std::sort (O(n log n))
    start = high_resolution_clock::now();
    std::sort(copy2, copy2 + n);
    stop = high_resolution_clock::now();
    double stdMs = duration_cast<microseconds>(stop - start).count() / 1000.0;

    // 3. Print results and ratio
    double ratio = (stdMs > 0) ? (bubbleMs / stdMs) : 0.0;

    cout << "n = " << n
         << " | Bubble: " << bubbleMs << " ms"
         << " | std::sort: " << stdMs << " ms"
         << " | Ratio (Bubble / std::sort): " << ratio << "x" << endl;

    delete[] copy1;
    delete[] copy2;
    return 0;
}