#include <iostream>
using namespace std;
// Function to find the maximum value that can be put in a knapsack of capacity W
int knapsack(int W, int wt[], int val[], int n) {
int dp[100][100]; // You can adjust size if needed
// Build table dp[][] in bottom-up manner
for (int i = 0; i <= n; i++) {
for (int w = 0; w <= W; w++) {
if (i == 0 || w == 0)
dp[i][w] = 0;
else if (wt[i - 1] <= w)
dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
else
dp[i][w] = dp[i - 1][w];
}
}
return dp[n][W];
}
int main() {
int n; // number of items
cout << "Enter number of items: ";

cin >> n;
int val[100], wt[100]; // arrays for values and weights
cout << "Enter values of items:\n";
for (int i = 0; i < n; i++)
cin >> val[i];
cout << "Enter weights of items:\n";
for (int i = 0; i < n; i++)
cin >> wt[i];
int W; // capacity of knapsack
cout << "Enter capacity of knapsack: ";
cin >> W;
cout << "\nMaximum value in Knapsack = " << knapsack(W, wt, val, n) << endl;
return 0;
 
