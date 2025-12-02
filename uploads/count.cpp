#include <iostream>
using namespace std;

void countingSort(int arr[], int n) {
    // 1. Find the minimum and maximum value
    int minVal = arr[0], maxVal = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }

    int range = maxVal - minVal + 1;

    // 2. Create count array
    int *count = new int[range];
    for (int i = 0; i < range; i++)
        count[i] = 0;

    // 3. Count frequency
    for (int i = 0; i < n; i++)
        count[arr[i] - minVal]++;

    // 4. Prefix sum
    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];

    // 5. Output array
    int *output = new int[n];

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
    }

    // 6. Copy back to original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    // Free memory
    delete[] count;
    delete[] output;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int *arr = new int[n];

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    countingSort(arr, n);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    delete[] arr;
    return 0;
}
