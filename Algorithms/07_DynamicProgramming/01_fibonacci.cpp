// Fibonacchi using DP(memoization)
// Fibonacci using DP(Tabulation)
#include <bits/stdc++.h>
using namespace std;

int fibMemo(int n, int dp[])
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    if (dp[n] != 0)
    {
        return dp[n];
    }

    int ans = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n] = ans;
}

int fibTab(int n, int dp[])
{
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    int dp[n] = {0}; // dp array to store the values of fib(n)
    cout << fib(n, dp) << endl;

    int dp2[n] = {0};
    cout << fibTab(n, dp2) << endl;

    return 0;
}