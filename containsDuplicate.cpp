#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        
        for (int n : nums) {
            if (seen.count(n)) {
                return true;
            }
            seen.insert(n);
        }
        
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Example 1: ";
    cout << (solution.containsDuplicate(nums1) ? "true" : "false") << endl;
    return 0;
}
