#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include <algorithm>
using namespace std;

// Binary Search with comparison counting
int binarySearch(int arr[], int n, int key) {
    int comparisons = 0;
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        comparisons++;
        if (arr[mid] == key) {
            break;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return comparisons;
}

int main() {
    srand(time(0));
    ofstream file("binary_search_results.csv");
    file << "Size,AverageComparisons,nlogn\n";

    const int MAX_SIZE = 1000;
    int arr[MAX_SIZE];

    for (int size = 30; size <= 1000; size += 10) {
        long long totalComparisons = 0;

        for (int t = 0; t < 10; t++) {
            for (int i = 0; i < size; i++) {
                arr[i] = rand() % 10000;
            }
            sort(arr, arr + size); // binary search requires sorted array
            int key = arr[rand() % size];
            totalComparisons += binarySearch(arr, size, key);
        }

        double avgComparisons = (double)totalComparisons / 10.0;
        double nlogn = size * log2(size);

        file << size << "," << avgComparisons << "," << nlogn << "\n";
        cout << "Size: " << size << " Avg: " << avgComparisons << " nlogn: " << nlogn << endl;
    }

    file.close();
    cout << "\nResults saved to 'binary_search_results.csv'\n";
    return 0;
}

