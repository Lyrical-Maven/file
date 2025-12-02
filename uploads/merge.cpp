#include <iostream>
#include <cstdlib>   // for rand(), srand()
#include <ctime>     // for time(0)
#include <cmath>     // for log2()
#include <fstream>
using namespace std;

// Merge function with comparison counting
int mergeAndCount(int arr[], int left, int mid, int right) {
    int comparisons = 0;

    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;

    return comparisons;
}

// Merge sort recursive function
int mergeSortAndCount(int arr[], int left, int right) {
    int comparisons = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        comparisons += mergeSortAndCount(arr, left, mid);
        comparisons += mergeSortAndCount(arr, mid + 1, right);

        comparisons += mergeAndCount(arr, left, mid, right);
    }
    return comparisons;
}

int main() {
    srand(time(0));
    ofstream file("merge_sort_results.csv");
    file << "Size,AverageComparisons,nlogn\n";

    const int MAX_SIZE = 1000;
    int arr[MAX_SIZE];

    for (int size = 30; size <= 1000; size += 10) {
        long long totalComparisons = 0;

        for (int t = 0; t < 10; t++) {
            for (int i = 0; i < size; i++) {
                arr[i] = rand() % 10000;
            }
            totalComparisons += mergeSortAndCount(arr, 0, size - 1);
        }

        double avgComparisons = (double)totalComparisons / 10.0;
        double nlogn = size * log2(size);

        file << size << "," << avgComparisons << "," << nlogn << "\n";
        cout << "Size: " << size
             << " Avg Comparisons: " << avgComparisons
             << " nlogn: " << nlogn << endl;
    }

    file.close();
    cout << "\nResults saved to 'merge_sort_results.csv'\n";
    return 0;
}

