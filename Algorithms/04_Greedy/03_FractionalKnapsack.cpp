#include <bits/stdc++.h>
using namespace std;

bool myCmp(pair<int, int> a, pair<int, int> b) {
    double r1 = (double)a.first / a.second;
    double r2 = (double)b.first / b.second;
    return r1 > r2;
}

double fractionalKnapsack(int W, pair<int, int> arr[], int n) {
    sort(arr, arr + n, myCmp);
    // sorting in descending order of ratio. ratio because we need to maximize the value
    int curWeight = 0;
    double finalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (curWeight + arr[i].second <= W) {
            curWeight += arr[i].second;
            finalValue += arr[i].first;
        } else {
            int remain = W - curWeight;
            finalValue += arr[i].first * ((double)remain / arr[i].second);
            break;
        }
    }
    return finalValue;
    // Time Complexity: O(nlogn)
    
}

int main() {
    int W = 50;
    pair<int, int> arr[] = {make_pair(60, 10), make_pair(100, 20), make_pair(120, 30)};
    int n = 3;
    cout << "Maximum value we can obtain = " << fractionalKnapsack(W, arr, n);
    return 0;
}