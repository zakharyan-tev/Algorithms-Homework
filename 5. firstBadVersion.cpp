#include <iostream>
using namespace std;

// Simulated bad version (for testing)
int BAD_VERSION = 4;

// Forward declaration of API
bool isBadVersion(int version) {
    return version >= BAD_VERSION;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (isBadVersion(mid)) {
                right = mid;
            } else {
                left = mid + 1; 
            }
        }
        
        return left; 
    }
};

int main() {
    Solution solution;

    int n = 10;
    cout << "First bad version: " << solution.firstBadVersion(n) << endl;

    return 0;
}
