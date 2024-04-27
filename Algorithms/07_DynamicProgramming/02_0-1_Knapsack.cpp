#include<bits/stdc++.h>
using namespace std;

int knapsack(int wt[], int val[], int W, int n)
{
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
            // base case
            {
                dp[i][w] = 0;
                // if there are no items or the capacity of the knapsack is 0, then the value will be 0
            }
            else if (wt[i - 1] <= w) 
            // if the weight of the current item is less than the capacity of the knapsack
            {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
                // we have two choices, either we can include the current item or we can exclude it
                // if we include the current item, then the value will be val[i-1] + dp[i-1][w-wt[i-1]]
                // if we exclude the current item, then the value will be dp[i-1][w]
                // we will take the maximum of the two values
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
                // if the weight of the current item is greater than the capacity of the knapsack,
                // then we will exclude the current item
            }
        }
    }

    return dp[n][W];
}

int main()
{
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    int wt[n], val[n];
    cout << "Enter the weight of the items: ";
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    cout << "Enter the value of the items: ";
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    int W;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    cout << "The maximum value that can be obtained is: " << knapsack(wt, val, W, n) << endl;

    return 0;
    // Time Complexity: O(n*W)
    // Space Complexity: O(n*W)
}