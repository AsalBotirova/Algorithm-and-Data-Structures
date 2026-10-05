#include <iostream>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

void bubleSort(int A[], int n) {
    for (int i= 0; i< n-1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (A[j] > A[j+1]) {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

int main() {
    int n = 100000;

    int* A = new int[n];
    for (int i = 0; i<n; i++) {
        A[i] = rand();
    }

    auto start = high_resolution_clock::now();
    bubleSort(A, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);

    cout<<"n = "<< n <<" | BubbleSort Time:  " << duration.count() << "us " << endl;

    delete [] A;
    return 0;
}
