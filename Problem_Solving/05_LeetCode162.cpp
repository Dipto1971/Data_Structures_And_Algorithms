#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }
};

// Example usage:
#include <iostream>
int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Peak element index for nums1: " << sol.findPeakElement(nums1) << endl;

    vector<int> nums2 = {1, 2, 1, 3, 5, 6, 4};
    cout << "Peak element index for nums2: " << sol.findPeakElement(nums2) << endl;

    return 0;
}
