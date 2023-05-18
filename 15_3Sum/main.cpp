#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

// Sort array, choose element from the vector and use two pointers to find correct sum
// Time Complexity: O(n^2)
// Space Complexity: O(1)

vector <vector<int>> threeSum(vector<int> &nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> output;
    for(int i=0; i<n-1; i++){
        int low = i + 1, high = n - 1;
        while(low < high){
            if(nums[i] + nums[low] + nums[high] < 0){
                low++;
            }
            else if(nums[i] + nums[low] + nums[high] > 0){
                high--;
            }
            else{
                output.push_back({nums[i], nums[low], nums[high]});
                int tempIndex1 = low, tempIndex2 = high;
                while(low < high && nums[low] == nums[tempIndex1]) low++;
                while(low < high && nums[high] == nums[tempIndex2]) high--;
            }
        }
        while(i+1 < n && nums[i] == nums[i+1]) i++;
    }
    return output;
}


int main() {
    std::vector arr{-1,0,1,2,-1,4};
    auto matrix = threeSum(arr);
    for(auto vec : matrix){
        for(auto item : vec){
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
}
