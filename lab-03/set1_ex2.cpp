#include <iostream>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

int linearSearch(int A[], int n, int key) {
    for (int i=0; i<n; i++) {
        if (A[i] == key )
            return i;
    }
    return -1;
}

int main() {
    int n = 100000;

    int* A = new int[n];
    for (int i=0; i<n; i++) {
        A[i] = rand();
    }

    // (a) Best Case: key is at index 0
    auto start = high_resolution_clock::now();
    linearSearch(A, n, A[0]);
    auto stop = high_resolution_clock::now();
    auto bestTime = duration_cast<microseconds>(stop - start).count();

    // (b) Average Case: key is near the middle
    start = high_resolution_clock::now();
    linearSearch(A, n, A[n/2]);
    stop = high_resolution_clock::now();
    auto avgTime = duration_cast<microseconds>(stop - start).count();

    // (c) Worst Case: key is not present (-999999 forces full array scan)
    start = high_resolution_clock::now();
    linearSearch(A, n, -9999);
    stop = high_resolution_clock::now();
    auto worstTime = duration_cast<microseconds>(stop - start).count();

    cout<< "n= " << n << " | Best: " << bestTime << " us"
    << " | Avg:  " << avgTime << " us"
    << " | Worst: " << worstTime << " us" << endl;

    delete [] A;
    return 0;
}