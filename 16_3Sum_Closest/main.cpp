#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

// Sort array, choose element from the vector and use two pointers to find correct sum
// Time Complexity: O(n^2)
// Space Complexity: O(1)

int threeSumClosest(vector<int> &nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int closest = INT32_MAX;
    for(int i=0; i<n-1; i++){
        int low = i + 1, high = n - 1;
        while(low < high){
            auto sum = nums[i] + nums[low] + nums[high];
            if(sum == target){
                return target;
            }
            if(abs(target - sum) < abs(target - closest)){
                closest = sum;
            }
            if(sum < target){
                low++;
            }
            else if(sum > target){
                high--;
            }
        }
        while(i+1 < n && nums[i] == nums[i+1]) i++;
    }
    return closest;
}


int main() {
    std::vector arr{-1,2,1,-4,4};
    std::cout << threeSumClosest(arr, 3);
}
