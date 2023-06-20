#include <iostream>
#include <vector>
#include <algorithm>

using std::string,std::vector;

int threeSumClosest(vector<int>& nums, int target) {
    int res =  INT32_MAX;
    sort(nums.begin(),nums.end());
    for(int i = 0; i < nums.size() - 2; ++i){
        int left = i+1;
        int right = nums.size() - 1;
        while(left < right){
            if(abs(target - res) > abs(target - (nums[left] + nums[i] + nums[right]))){
                res = nums[left] + nums[i] + nums[right];
            }
            if(nums[left] + nums[i] + nums[right] > target){
                --right;
            }
            else{
                ++left;
            }
        }
    }
    return res;
}

int main() {
    vector<int> arr{-1,2,1,-4};
    threeSumClosest(arr,1);
}
