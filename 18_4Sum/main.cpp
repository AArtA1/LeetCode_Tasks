#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

// The same idea that we used in task about 3Sum
// Time Complexity: O(n^3)
// Space Complexity: O(1)

vector <vector<int>> fourSum(vector<int> &nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> output;
    for(int i=0; i<n-2; i++){
        for(int j = i+1; j < n - 3;++j){
            int low = i + 1, high = n - 1;
            while(low < high){
                if(nums[i] + nums[j] + nums[low] + nums[high] < 0){
                    low++;
                }
                else if(nums[i] + nums[j] + nums[low] + nums[high] > 0){
                    high--;
                }
                else{
                    output.push_back({nums[i],nums[j], nums[low], nums[high]});
                    int tempIndex1 = low, tempIndex2 = high;
                    while(low < high && nums[low] == nums[tempIndex1]) low++;
                    while(low < high && nums[high] == nums[tempIndex2]) high--;
                }
            }
            while(i+1 < n && nums[i] == nums[i+1]) i++;
        }
    }
    return output;
}


int main() {
    std::vector arr{-1,0,1,0,-2,2};
    auto matrix = fourSum(arr,2);
    for(auto vec : matrix){
        for(auto item : vec){
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
}
