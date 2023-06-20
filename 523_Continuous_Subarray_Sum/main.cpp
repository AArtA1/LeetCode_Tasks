#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector, std::unordered_map;

bool checkSubarraySum(vector<int> &nums, int k) {
    if (nums.size() < 2) {
        return false;
    }
    unordered_map<int, std::pair<int, int>> map;
    int counter = 0;
    map[0] = {1, -1};
    int i = 0;
    for (auto item: nums) {
        counter = (counter + (item % k + k)) % k;
        if (map[counter].first == 0) {
            map[counter].second = i;
        }
        if (map[counter].first >= 1 && i - map[counter].second >= 2) {
            return true;
        }
        ++map[counter].first;
        ++i;
    }
    return false;
}

int main() {
    std::vector<int> arr{5, 0, 0, 0};
    std::cout << checkSubarraySum(arr, 6);
}
