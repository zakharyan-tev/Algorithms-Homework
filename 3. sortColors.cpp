#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1; 
    
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quick_sort_helper(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot_idx = partition(arr, low, high);
        quick_sort_helper(arr, low, pivot_idx - 1);
        quick_sort_helper(arr, pivot_idx + 1, high);
    }
}

void quick_sort(vector<int>& arr) {
    if (arr.size() <= 1) return;
    quick_sort_helper(arr, 0, arr.size() - 1);
}

class Solution {
public:
    void sortColors(vector<int>& nums) {
        quick_sort(nums);
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    solution.sortColors(nums);
    cout << "Sorted: ";
    for (int n : nums) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
