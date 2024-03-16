#include<bits/stdc++.h>
using namespace std;

int minCoins(int coins[], int n, int amount) {
    sort(coins, coins+n, greater<int>());
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(coins[i] <= amount) {
            int c = floor(amount/coins[i]);
            ans += c;
            amount -= c*coins[i];
        }
        if(amount == 0) {
            break;
        }
    }
    return ans;
}

int main() {
    int n =5;
    int coins[n] = {1, 2, 5, 10, 20};
    int amount = 50;
    cout << minCoins(coins, n, amount) << endl;
    return 0;
}