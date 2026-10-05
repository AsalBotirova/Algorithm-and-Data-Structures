#include <iostream>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

const int CAP = 100000;
int A[CAP]; // Static array allocated at compile time

int main() {
    int n = 100000; // Test values: 1000, 5000, 10000, 50000, 100000

    int* B = new int[n]; // Dynamic array allocated at runtime

    // 1. Time filling Static Array A
    auto start = high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        A[i] = rand();
    }
    auto stop = high_resolution_clock::now();
    auto staticTime = duration_cast<microseconds>(stop - start).count();

    // 2. Time filling Dynamic Array B
    start = high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        B[i] = rand();
    }
    stop = high_resolution_clock::now();
    auto dynamicTime = duration_cast<microseconds>(stop - start).count();

    // 3. Print results and space footprint
    cout << "n = " << n
         << " | Static Fill: " << staticTime << " us"
         << " | Dynamic Fill: " << dynamicTime << " us"
         << " | Dynamic Bytes: " << n * sizeof(int) << " bytes" << endl;

    delete[] B;
    return 0;
}