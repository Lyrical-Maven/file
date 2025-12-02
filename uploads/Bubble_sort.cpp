#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
using namespace std;

// Bubble Sort with comparison counting
int bubbleSort(int arr[], int n) {
    int comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return comparisons;
}

int main() {
    srand(time(0));
    ofstream file("bubble_sort_results.csv");
    file << "Size,AverageComparisons,nlogn\n";

    const int MAX_SIZE = 1000;
    int arr[MAX_SIZE];

    for (int size = 30; size <= 1000; size += 10) {
        long long totalComparisons = 0;

        for (int t = 0; t < 10; t++) {
            for (int i = 0; i < size; i++) {
                arr[i] = rand() % 10000;
            }
            totalComparisons += bubbleSort(arr, size);
        }

        double avgComparisons = (double)totalComparisons / 10.0;
        double nlogn = size * log2(size);

        file << size << "," << avgComparisons << "," << nlogn << "\n";
        cout << "Size: " << size << " Avg: " << avgComparisons << " nlogn: " << nlogn << endl;
    }

    file.close();
    cout << "\nResults saved to 'bubble_sort_results.csv'\n";
    return 0;
}

