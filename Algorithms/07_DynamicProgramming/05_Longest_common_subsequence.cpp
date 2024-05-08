#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2, int n, int m){
    if(n==0 || m==0){
        return 0;
    }
    if(s1[n-1]==s2[m-1]){
        return 1+lcs(s1, s2, n-1, m-1);
        // If last characters of both strings match,
        // then length of LCS is 1 plus length of LCS of remaining strings.
    }
    else{
        return max(lcs(s1, s2, n-1, m), lcs(s1, s2, n, m-1));
        // If last characters of both strings do not match,
        // then LCS can be obtained by recursively finding LCS of
        // 1. all characters of s1 except last
        // 2. all characters of s2 except last
    }
    // Time complexity: O(2^n)
}

int lcs_memoization(string s1, string s2, int n, int m){
    int dp[n+1][m+1];
    // dp[i][j] represents the length of LCS of s1[0..i-1] and s2[0..j-1]
    // this updates the dp array in bottom-up manner
    
    if (dp[m][n] != -1) {
        // checks if the value is already calculated
        return dp[m][n];
    }
    if(n==0 || m==0){
        dp[m][n] = 0;
        // If any of the string is empty then there is no common subsequence
    }
    if(s1[n-1]==s2[m-1]){
        dp[m][n] = 1+lcs(s1, s2, n-1, m-1);
        // If last characters of both strings match,
        // then length of LCS is 1 plus length of LCS of remaining strings.
    }
    else{
        dp[m][n] = max(lcs(s1, s2, n-1, m), lcs(s1, s2, n, m-1));
        // If last characters of both strings do not match,
        // then LCS can be obtained by recursively finding LCS of
        // 1. all characters of s1 except last or
        // 2. all characters of s2 except last
    }
    return dp[n][m];

    // Time complexity: O(n*m)
}

int lcs_tabulation(string s1, string s2, int n, int m){
    int dp[n+1][m+1];
    // dp[i][j] represents the length of LCS of s1[0..i-1] and s2[0..j-1]
    // this updates the dp array in bottom-up manner
    
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
                // If any of the string is empty then there is no common subsequence
            }
            else if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
                // If last characters of both strings match,
                // then length of LCS is 1 plus length of LCS of remaining strings.
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                // If last characters of both strings do not match,
                // then LCS can be obtained by recursively finding LCS of
                // 1. all characters of s1 except last or
                // 2. all characters of s2 except last
            }
        }
    }
    return dp[n][m];
    // Time complexity: O(n*m)
}

int main(){
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    int n = s1.length();
    int m = s2.length();
    cout<<lcs(s1, s2, n, m);
    return 0;
}