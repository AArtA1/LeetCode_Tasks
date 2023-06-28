#include <iostream>
#include <vector>

using std::vector;


// Time Complexity: O(nlogn)
// Space Complexity: O(n)

int minSubArrayLen(int target, vector<int>& nums) {
    // Get the length of the input vector
    int n = nums.size();
    // If the vector is empty, return 0
    if (n == 0)
        return 0;
    // Initialize the minimum subarray length to INT_MAX-1
    int ans = INT_MAX - 1;
    // Create a new vector "sums" with size n+1, initialized
    // to all zeros
    vector<int> sums(n + 1, 0);
    // Compute the running sum of nums and store it in
    // "sums"
    for (int i = 1; i <= n; i++)
        sums[i] = sums[i - 1] + nums[i - 1];
    // Iterate through each starting index i
    for (int i = 1; i <= n; i++) {
        // Calculate the target sum for the subarray
        // starting at index i
        int to_find = target + sums[i - 1];
        // Find the first element in "sums" that is >=
        // to_find
        auto bound = lower_bound(sums.begin(), sums.end(),
                                 to_find);
        // If such an element is found and it is not equal
        // to to_find itself
        if (bound != sums.end()) {
            // Compute the length of the subarray and update
            // ans if necessary
            int len = bound - (sums.begin() + i - 1);
            ans = std::min(ans, len);
        }
    }
    // Return ans if it was updated, otherwise return 0
    return (ans != INT_MAX - 1) ? ans : 0;
}


// Time Complexity: O(n)
// Space Complexity: O(1)

int minSubArrayLen(int s, vector<int>& nums) {
    int l = 0, r = 0, n = nums.size(), sum = 0, len = INT_MAX;
    while (r < n) {
        sum += nums[r++];
        while (sum >= s) {
            len = std::min(len, r - l);
            sum -= nums[l++];
        }
    }
    return len == INT_MAX ? 0 : len;
}


int main() {
    std::vector<int> arr{2,3,1,2,4,3};
    std::cout << minSubArrayLen(7,arr);
}
