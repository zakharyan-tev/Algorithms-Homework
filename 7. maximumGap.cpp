#include <vector>

class Solution {
public:
    int maximumGap(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return 0;
        }
        int minVal = nums[0];
        int maxVal = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] < minVal) {
                minVal = nums[i];
            }
            if (nums[i] > maxVal) {
                maxVal = nums[i];
            }
        }

        if (minVal == maxVal) {
            return 0;
        }

        int bucketSize = (maxVal - minVal) / (n - 1);
        if (bucketSize == 0) {
            bucketSize = 1;
        }
        int bucketCount = (maxVal - minVal) / bucketSize + 1;

        std::vector<int> bucketMin(bucketCount);
        std::vector<int> bucketMax(bucketCount);
        std::vector<bool> used(bucketCount, false);

        for (int i = 0; i < n; i++) {
            int idx = (nums[i] - minVal) / bucketSize;

            if (!used[idx]) {
                bucketMin[idx] = nums[i];
                bucketMax[idx] = nums[i];
                used[idx] = true;
            } else {
                if (nums[i] < bucketMin[idx]){
                    bucketMin[idx] = nums[i];
                }
                if (nums[i] > bucketMax[idx]){
                    bucketMax[idx] = nums[i];
                }
            }
        }

        int maxGap = 0;
        int prevMax = minVal;

        for (int i = 0; i < bucketCount; i++) {
            if (!used[i]) {
                continue;
            }
            int gap = bucketMin[i] - prevMax;
            if (gap > maxGap){
                maxGap = gap;
            }
            prevMax = bucketMax[i];
        }

        return maxGap;
    }
};
