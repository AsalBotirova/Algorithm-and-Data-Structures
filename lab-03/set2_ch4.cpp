#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

int main() {
    int n = 50000; // Test values: 1000, 10000, 50000, 100000

    // 1. Dynamic Array
    auto start = high_resolution_clock::now();
    int* arr = new int[n];
    for (int i = 0; i < n; i++) arr[i] = rand();
    auto stop = high_resolution_clock::now();
    double arrMs = duration_cast<microseconds>(stop - start).count() / 1000.0;

    // 2. std::vector
    start = high_resolution_clock::now();
    vector<int> vec;
    vec.reserve(n);
    for (int i = 0; i < n; i++) vec.push_back(rand());
    stop = high_resolution_clock::now();
    double vecMs = duration_cast<microseconds>(stop - start).count() / 1000.0;

    // 3. Singly Linked List
    start = high_resolution_clock::now();
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < n; i++) {
        Node* newNode = new Node(rand());
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    stop = high_resolution_clock::now();
    double listMs = duration_cast<microseconds>(stop - start).count() / 1000.0;

    // Memory Footprints
    long long arrBytes = n * sizeof(int);
    long long vecBytes = n * sizeof(int);
    long long listBytes = n * sizeof(Node); // int + pointer overhead

    cout << "n = " << n << endl;
    cout << "  Array  | Time: " << arrMs << " ms | Space: " << arrBytes / 1024.0 << " KB" << endl;
    cout << "  Vector | Time: " << vecMs << " ms | Space: " << vecBytes / 1024.0 << " KB" << endl;
    cout << "  List   | Time: " << listMs << " ms | Space: " << listBytes / 1024.0 << " KB" << endl;

    // Clean up memory
    delete[] arr;
    Node* curr = head;
    while (curr) {
        Node* tmp = curr;
        curr = curr->next;
        delete tmp;
    }

    return 0;
}