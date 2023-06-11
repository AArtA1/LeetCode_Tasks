#include <iostream>
#include <vector>

using std::vector;

int longestOnes(vector<int> &nums, int k) {
    if (nums.size() == 0) {
        return 0;
    }
    vector<int> arr(2);
    int beg = 0, largestCount = 0;
    for (int end = 0; end < nums.size(); end++) {
        if (nums[end] != 0) {
            largestCount = std::max(largestCount, ++arr[nums[end]]);
        }
        if (end - beg + 1 - largestCount > k) {
            arr[nums[beg++]]--;
        }
    }
    return nums.size() - beg;
}

int main() {
    vector<int> arr{1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    longestOnes(arr, 2);
}
