#include <iostream>
using namespace std;

// Function to multiply two 2x2 matrices using Strassen's algorithm
void strassenMultiply(int A[2][2], int B[2][2], int C[2][2]) {
    // Extract elements of matrices
    int a = A[0][0], b = A[0][1],
        c = A[1][0], d = A[1][1];

    int e = B[0][0], f = B[0][1],
        g = B[1][0], h = B[1][1];

    // Compute the 7 products (Strassen’s formula)
    int p1 = a * (f - h);
    int p2 = (a + b) * h;
    int p3 = (c + d) * e;
    int p4 = d * (g - e);
    int p5 = (a + d) * (e + h);
    int p6 = (b - d) * (g + h);
    int p7 = (a - c) * (e + f);

    // Compute the final matrix elements
    C[0][0] = p5 + p4 - p2 + p6;
    C[0][1] = p1 + p2;
    C[1][0] = p3 + p4;
    C[1][1] = p1 + p5 - p3 - p7;
}

int main() {
    int A[2][2], B[2][2], C[2][2];

    cout << "Enter elements of first 2x2 matrix (row-wise):\n";
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cin >> A[i][j];

    cout << "Enter elements of second 2x2 matrix (row-wise):\n";
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cin >> B[i][j];

    // Perform multiplication using Strassen’s algorithm
    strassenMultiply(A, B, C);

    // Display result
    cout << "Resultant matrix after multiplication:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }

    return 0;
}

