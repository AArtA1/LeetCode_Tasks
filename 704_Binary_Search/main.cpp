#include <iostream>
#include <vector>

using std::vector;

int search(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    vector<int> arr{-1, 0, 3, 5, 9, 12};
    std::cout << search(arr, 9);
}
