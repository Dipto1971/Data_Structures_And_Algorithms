#include<bits/stdc++.h>
using namespace std;

bool compare (pair<int, int> a, pair<int, int> b){
    return a.second < b.second; 
    //if a.second is shorter than place a before b
}

int maxActivities(pair<int, int> arr[], int n){
    sort(arr, arr+n, compare); // sort the array based on the end time
    int res = 1;
    int prev = 0;
    for(int i = 0; i < n; i++){
        cout << arr[i].first << " " << arr[i].second << endl;
    }
    for(int curr = 1; curr < n; curr++){
        if(arr[curr].first >= arr[prev].second){
            res++;
            prev = curr;
        }
    }
    return res;
}

int main(){
    int n; cin >> n;
    pair<int, int> arr[n];
    for(int i = 0; i < n; i++){
        int start, end; 
        cout << "Enter start and end time for activity " << i+1 << ": ";
        cin >> start >> end;
        arr[i] = make_pair(start, end);
    }
    cout << maxActivities(arr, n) << endl;
    return 0;
}