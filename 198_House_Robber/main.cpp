#include <iostream>
#include <vector>

using std::vector;

int rob(vector<int> &nums) {
    if (nums.size() == 1) {
        return nums[0];
    }
    if (nums.size() == 2) {
        return nums[0] > nums[1] ? nums[0] : nums[1];
    }
    std::pair<int, int> pr = {0, 0};
    for (int i = 0; i < nums.size(); ++i) {
        int temp = pr.first + nums[i];
        pr.first = std::max(pr.second, pr.first);
        pr.second = std::max(pr.second, temp);
    }
    return std::max(pr.first, pr.second);
}

int main() {
    vector<int> arr = {1, 2, 3, 1, 2,3};
    std::cout << rob(arr);
}
