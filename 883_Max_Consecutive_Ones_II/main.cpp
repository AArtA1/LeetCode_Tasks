#include <iostream>
#include <vector>

using std::vector;

int findMaxConsecutiveOnes(vector<int> &nums) {
    int n = nums.size(), ans = 0, dp0 = 0, dp1 = 0;
    for (int i = 0; i < n; ++i){
        if (nums[i] != 0){
            dp1++;
            dp0++;
        } else{
            dp1 = dp0 + 1;
            dp0 = 0;
        }
        ans = std::max(ans, std::max(dp0, dp1));
    }
    return ans;
}

int main() {
    vector<int> arr{1,0,1,1,0};
    std::cout << findMaxConsecutiveOnes(arr);
}
