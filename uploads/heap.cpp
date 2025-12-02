#include <iostream>
#include <cstdlib>   // for rand(), srand()
#include <ctime>     // for time(0)
#include <cmath>     // for log2()
#include <fstream>
using namespace std;

// Heapify function with comparison counting
int heapify(int arr[], int n, int i) {
    int comparisons = 0;
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n) {
        comparisons++;
        if (arr[left] > arr[largest])
            largest = left;
    }

    if (right < n) {
        comparisons++;
        if (arr[right] > arr[largest])
            largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        comparisons += heapify(arr, n, largest);
    }

    return comparisons;
}

// Heap Sort function
int heapSort(int arr[], int n) {
    int comparisons = 0;

    // Build heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        comparisons += heapify(arr, n, i);
    }

    // Extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        comparisons += heapify(arr, i, 0);
    }

    return comparisons;
}

int main() {
    srand(time(0));
    ofstream file("heap_sort_results.csv");
    file << "Size,AverageComparisons,nlogn\n";

    const int MAX_SIZE = 1000;
    int arr[MAX_SIZE];

    for (int size = 30; size <= 1000; size += 10) {
        long long totalComparisons = 0;

        for (int t = 0; t < 10; t++) {
            for (int i = 0; i < size; i++) {
                arr[i] = rand() % 10000;
            }

            totalComparisons += heapSort(arr, size);
        }

        double avgComparisons = (double)totalComparisons / 10.0;
        double nlogn = size * log2(size);

        file << size << "," << avgComparisons << "," << nlogn << "\n";
        cout << "Size: " << size
             << " Avg Comparisons: " << avgComparisons
             << " nlogn: " << nlogn << endl;
    }

    file.close();
    cout << "\nResults saved to 'heap_sort_results.csv'\n";
    return 0;
}

