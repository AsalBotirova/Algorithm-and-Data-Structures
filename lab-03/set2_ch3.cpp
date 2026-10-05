#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Naive Recursive Fibonacci - O(2^n)
long long fibRecursive(int n) {
    if (n <= 1) return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

// Iterative Fibonacci - O(n)
long long fibIterative(int n) {
    if (n <= 1) return n;
    long long a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        long long next = a + b;
        a = b;
        b = next;
    }
    return b;
}

int main() {
    int n = 10; // Test values: 10, 20, 30, 35, 40

    // 1. Time Recursive Fibonacci
    auto start = high_resolution_clock::now();
    long long resRec = fibRecursive(n);
    auto stop = high_resolution_clock::now();
    double recMs = duration_cast<microseconds>(stop - start).count() / 1000.0;

    // 2. Time Iterative Fibonacci
    start = high_resolution_clock::now();
    long long resIter = fibIterative(n);
    stop = high_resolution_clock::now();
    double iterUs = duration_cast<microseconds>(stop - start).count();

    cout << "n = " << n
         << " | Recursive: " << recMs << " ms"
         << " | Iterative: " << iterUs << " us"
         << " | Result: " << resRec << endl;

    return 0;
}