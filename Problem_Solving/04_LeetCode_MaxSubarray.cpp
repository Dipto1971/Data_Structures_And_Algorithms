#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& v) {
        int maxEndingHere = v[0];
        int maxSoFar = v[0];
        
        for (int i = 1; i < v.size(); i++) {
            maxEndingHere = max(v[i], maxEndingHere + v[i]);
            maxSoFar = max(maxSoFar, maxEndingHere);
        }
        
        return maxSoFar;
    }
};

int main() {
    // Example usage
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution solution;
    int maxSum = solution.maxSubArray(nums);
    cout << "Maximum subarray sum: " << maxSum << endl;
    
    return 0;
}
