#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
using namespace std;

// Linear Search with comparison counting
int linearSearch(int arr[], int n, int key) {
    int comparisons = 0;
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == key) {
            break; // found
        }
    }
    return comparisons;
}

int main() {
    srand(time(0));
    ofstream file("linear_search_results.csv");
    file << "Size,AverageComparisons,nlogn\n";

    const int MAX_SIZE = 1000;
    int arr[MAX_SIZE];

    for (int size = 30; size <= 1000; size += 10) {
        long long totalComparisons = 0;

        for (int t = 0; t < 10; t++) {
            for (int i = 0; i < size; i++) {
                arr[i] = rand() % 10000;
            }
            int key = arr[rand() % size]; // pick a random element to search
            totalComparisons += linearSearch(arr, size, key);
        }

        double avgComparisons = (double)totalComparisons / 10.0;
        double nlogn = size * log2(size);

        file << size << "," << avgComparisons << "," << nlogn << "\n";
        cout << "Size: " << size << " Avg: " << avgComparisons << " nlogn: " << nlogn << endl;
    }

    file.close();
    cout << "\nResults saved to 'linear_search_results.csv'\n";
    return 0;
}

