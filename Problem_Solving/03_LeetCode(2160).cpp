#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSum(int num) {
        int n[4];
        for (int i=0; i<4; i++){
            int temp = num % 10;
            num /= 10;
            n[i] = temp;
        }
        sort (n, n+4);
        return (n[0]*10 + n[3] + n[1]*10 + n[2]); 
    }
};
int main() {
    int num = 4321;
    Solution s;
    cout << s.minimumSum(num) << endl;
    return 0;
}