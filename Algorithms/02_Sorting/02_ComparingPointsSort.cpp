#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

bool compare(Point p1, Point p2) {
    return p1.x < p2.x;
    // Here we are sorting the points in increasing order of x
}

int main(){
    Point arr[] = {{3, 10}, {2, 8}, {5, 4}};
    //Point is a structure with two fields x and y
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n, compare);
    for (auto p : arr) {
        cout << p.x << " " << p.y << endl;
    }
    cout << endl;
}