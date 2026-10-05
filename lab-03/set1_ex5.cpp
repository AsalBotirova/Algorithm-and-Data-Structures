#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

int main() {
    int n = 100000; // Test values: 1000, 5000, 10000, 50000, 100000

    // (a) Un-reserved vector (watches capacity jumps)
    vector<int> v;
    size_t old_cap = 0;
    int jumps = 0;

    auto start = high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        v.push_back(rand());
        if (v.capacity() != old_cap) {
            old_cap = v.capacity();
            jumps++;
        }
    }
    auto stop = high_resolution_clock::now();
    auto unreservedTime = duration_cast<microseconds>(stop - start).count();

    // (b) Reserved vector ahead of time
    vector<int> w;
    start = high_resolution_clock::now();
    w.reserve(n);
    for (int i = 0; i < n; i++) {
        w.push_back(rand());
    }
    stop = high_resolution_clock::now();
    auto reservedTime = duration_cast<microseconds>(stop - start).count();

    cout << "n = " << n
         << " | push_back only: " << unreservedTime << " us"
         << " | reserve + push_back: " << reservedTime << " us"
         << " | Capacity Jumps: " << jumps << endl;

    return 0;
}