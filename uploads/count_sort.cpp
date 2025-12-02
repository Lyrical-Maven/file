#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
using namespace std;

// Counting Sort that counts comparisons (min/max comparisons only)
int countSortComparisons(int arr[], int n) {
    int comparisons = 0;

    // 1. Find min and max (these generate comparisons)
    int minVal = arr[0];
    int maxVal = arr[0];

    for (int i = 1; i < n; i++) {
        comparisons++;
        if (arr[i] < minVal) minVal = arr[i];

        comparisons++;
        if (arr[i] > maxVal) maxVal = arr[i];
    }

    // 2. Counting frequencies
    int range = maxVal - minVal + 1;
    int *count = new int[range];

    for (int i = 0; i < range; i++)
        count[i] = 0;

    for (int i = 0; i < n; i++)
        count[arr[i] - minVal]++;

    // 3. Prefix sum (no comparisons needed)
    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];

    delete[] count;
    return comparisons;
}

int main() {
    srand(time(0));
    ofstream file("countsort_results.csv");
    file << "Size,AverageComparisons,nlogn\n";

    const int MAX_SIZE = 1000;
    int arr[MAX_SIZE];

    for (int size = 30; size <= 1000; size += 10) {
        int totalComparisons = 0;

        for (int t = 0; t < 10; t++) {
            // fill array with random values
            for (int i = 0; i < size; i++)
                arr[i] = rand() % 10000;

            // count comparisons
            totalComparisons += countSortComparisons(arr, size);
        }

        double avg = (double)totalComparisons / 10.0;
        double nlogn = size * log2(size);

        file << size << "," << avg << "," << nlogn << "\n";

        cout << "Size: " << size
             << " Avg Comparisons: " << avg
             << " nlogn: " << nlogn << endl;
    }

    file.close();
    cout << "\nResults saved to 'countsort_results.csv'\n";
    return 0;
}
