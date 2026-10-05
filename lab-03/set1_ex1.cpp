#include <iostream>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

int arraySum(int A[], int n) {
    int sum = 0;
    for (int i =0; i<n; i++) {
        sum += A[i];
    }
    return sum;
}

int main() {
    int n = 100000;

    int* A = new int[n];
    for (int i=0; i<n; i++) {
        A[i] = rand();
    }

    auto start = high_resolution_clock::now();
    int total = arraySum(A, n);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop-start);
    cout << "n = " << n << " | Time: " << duration.count() << "microseconds" << endl;

    delete [] A;
    return 0;
}
