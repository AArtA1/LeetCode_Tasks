#include <iostream>
#include <vector>

using std::vector;


// Суть в том, чтобы заполнить два массива максимальных с левой и правой сторон для каждого из элементов. После чего пройти по массиву и найти разницу между минимумом среди левого и правого максимумов.
// Time Complexity: O(n)
// Space Complexity: O(n)
void findMax(const vector<int> &height, vector<int> &leftMax, vector<int> &rightMax) {
    int max = INT32_MIN;
    for (int i = 0; i < height.size(); ++i) {
        leftMax[i] = max;
        max = std::max(max, height[i]);
    }
    max = INT32_MIN;
    for (int i = height.size() - 1; i >= 0; --i) {
        rightMax[i] = max;
        max = std::max(max, height[i]);
    }
}

int trap(vector<int> &height) {
    vector<int> leftMax(height.size());
    vector<int> rightMax(height.size());
    findMax(height, leftMax, rightMax);
    int sum = 0;
    for (int i = 1; i < height.size() - 1; ++i) {
        if (height[i] < std::min(leftMax[i], rightMax[i])) {
            sum += std::min(leftMax[i], rightMax[i]) - height[i];
        }
    }
    return sum;
}

int main() {
    vector<int> arr{1,8,6,2,5,4,8,3,7};
    std::cout << trap(arr);
}