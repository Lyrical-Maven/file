#include <iostream>
#include <cstdlib>  //for rand() and srand()
#include <ctime>    // for time(0)
#include <cmath>    //for log2()
#include <fstream>
using namespace std;

// Insertion Sort with comparison count
int insertionSort(int arr[], int n) {
    int comparisons = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            comparisons++; // Count comparison between arr[j] and key
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
    return comparisons;
}

int main() {
    /*rand() uses an internal seed value to generate random numbers.

If you donot call srand(), the seed defaults to 1 ? same sequence every run.

srand() sets a new seed ? changes the sequence.
    */
    srand(time(0));   // seed with current time
    ofstream file("insertion_sort_results.csv");
    file << "Size,AverageComparisons,nlogn\n";

    const int MAX_SIZE = 1000;
    int arr[MAX_SIZE]; // Single array reused for all runs

    for (int size = 30; size <= 1000; size += 10) {
        int totalComparisons = 0;

        for (int t = 0; t < 10; t++) {
            // Fill array with random values
            for (int i = 0; i < size; i++) {
                arr[i] = rand() % 10000;   // random numbers 0–9999
/*
rand() ? returns a pseudo-random integer between 0 and RAND_MAX (a big constant, often 32767 or higher).

% 10000 ? modulus operator, keeps only the remainder when divided by 10000.

Result ? integer in the range 0 to 9999.
*/
            }

            // Sort and count comparisons
            totalComparisons += insertionSort(arr, size);
        }

        double avgComparisons = (double) totalComparisons / 10.0;
        double nlogn = size * log2(size);

        file << size << "," << avgComparisons << "," << nlogn << "\n";
        cout << "Size: " << size 
             << " Avg Comparisons: " << avgComparisons 
             << " nlogn: " << nlogn << endl;
    }

    file.close();
    cout << "\nResults saved to 'insertion_sort_results.csv'\n";
    return 0;
}
