#include<bits/stdc++.h>
using namespace std;

int lps(string s, int n){
    int dp[n][n];
    // dp[i][j] represents the length of LPS of s[i..j]
    // this updates the dp array in bottom-up manner
    
    for(int i=0; i<n; i++){
        dp[i][i] = 1;
        // The length of the longest palindromic subsequence of a single character is 1
    }
    
    for(int len=2; len<=n; len++){
        for(int i=0; i<n-len+1; i++){
            int j = i+len-1;
            if(s[i]==s[j] && len==2){
                dp[i][j] = 2;
                // If the first and last characters match and the length of the string is 2
            }
            else if(s[i]==s[j]){
                dp[i][j] = 2+dp[i+1][j-1];
                // If the first and last characters match
            }
            else{
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                // If the first and last characters do not match
            }
        }
    }
    return dp[0][n-1];
}