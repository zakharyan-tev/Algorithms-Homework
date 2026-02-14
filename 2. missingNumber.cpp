#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i) {
                return i;
            }
        }
        return nums.size();
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {0, 1};
    cout << "Example 1: " << solution.missingNumber(nums1) << endl;

    return 0;
}
