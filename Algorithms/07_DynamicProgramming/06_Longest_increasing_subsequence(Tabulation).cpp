#include<bits/stdc++.h>
using namespace std;

int lis(int arr[], int n){
    int dp[n];
    dp[0] = 1;
    // The length of the longest increasing subsequence ending at index 0 is 1
    
    for(int i=1; i<n; i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(arr[i]>arr[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    return *max_element(dp, dp+n);
}

int main(){
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<lis(arr, n)<<endl;
    return 0;
}