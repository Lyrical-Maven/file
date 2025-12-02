#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
using namespace std;

long long comparisons;  // global counter

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisons++; // comparison with pivot
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// QuickSort recursive function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    srand(time(0));
    ofstream file("quick_sort_results.csv");
    file << "Size,AverageComparisons,nlogn\n";

    const int MAX_SIZE = 1000;
    int arr[MAX_SIZE];

    for (int size = 30; size <= 1000; size += 10) {
        long long totalComparisons = 0;

        for (int t = 0; t < 10; t++) {
            for (int i = 0; i < size; i++) {
                arr[i] = rand() % 10000;  // random array
            }

            comparisons = 0;
            quickSort(arr, 0, size - 1);
            totalComparisons += comparisons;
        }

        double avgComparisons = (double) totalComparisons / 10.0;
        double nlogn = size * log2(size);

        file << size << "," << avgComparisons << "," << nlogn << "\n";
        cout << "Size: " << size 
             << " Avg Comparisons: " << avgComparisons 
             << " nlogn: " << nlogn << endl;
    }

    file.close();
    cout << "\nResults saved to 'quick_sort_results.csv'\n";
    return 0;
}

