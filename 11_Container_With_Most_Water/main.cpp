#include <iostream>
#include <vector>
typedef long long ll;

using std::vector, std::cin;

// Time Complexity: O(n)
// Space Complexity: O(1)

int maxArea(vector<int> &height) {
    int n = height.size();
    int right = n - 1;
    int max = 0;
    for (int left = 0; left != right;) {
        max = std::max(std::min(height[left], height[right]) * (right - left), max);
        if (height[left] < height[right]) {
            ++left;
        } else {
            --right;
        }
    }
    return max;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    std::cout << maxArea(arr);
}
