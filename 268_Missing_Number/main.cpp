#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int missingNumber(vector<int> &nums) {
    vector<bool> array(nums.size() + 1, false);
    for (int i = 0; i < nums.size(); ++i) {
        array[nums[i]] = true;
    }
    auto result = std::find_if(array.begin(), array.end(), [](bool value) { return !value; });
    return result - array.begin();
}

int main() {
    std::vector<int> arr{9, 6, 4, 2, 3, 5, 7, 0, 1};
    std::cout << missingNumber(arr);
}
