#include <iostream>
#include <vector>

using std::vector;

int longestSubarray(vector<int> &nums) {
    int d0 = 0, d1 = 0;
    int max = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != 0) {
            ++d0;
            ++d1;
        } else {
            d1 = d0 + 1;
            d0 = 0;
        }
        max = std::max(max, std::max(d0 - 1, d1 - 1));
    }
    return max;
}


int main() {
    vector<int> arr{1, 1, 0, 1};
    std::cout << longestSubarray(arr);
}
