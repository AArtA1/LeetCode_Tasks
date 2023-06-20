#include <iostream>
#include <vector>

using std::vector;


// Time Complexity: O(logn + k)
// Space Complexity: O(1)
vector<int> findClosestElements(vector<int> &arr, int k, int x) {
    if (arr.size() == 1) {
        return arr;
    }
    auto end = std::lower_bound(arr.begin(), arr.end(), x);
    auto begin = end - 1;
    if (end == arr.end()) {
        return {arr.end() - k, arr.end()};
    }
    int counter = 0;
    while (counter != k) {
        if (begin < arr.begin()) {
            ++end;
            ++counter;
            continue;
        }
        if (end == arr.end()) {
            --begin;
            ++counter;
            continue;
        }
        if (abs(*begin - x) <= abs(*end - x)) {
            --begin;
        } else {
            ++end;
        }
        ++counter;
    }
    return {begin + 1, end};
}

int main() {
    vector<int> arr{1, 2, 3, 4, 5};
    auto a = findClosestElements(arr, 4, -1);
}
