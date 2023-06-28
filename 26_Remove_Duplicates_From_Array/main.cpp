#include <iostream>
#include <vector>

using std::vector;

int removeDuplicates(vector<int>& nums) {
    if(nums.empty()){
        return 0;
    }
    if(nums.size() == 1){
        return 1;
    }
    int left = 0;
    int right;
    for(right = 0; right < nums.size() - 1; ++right){
        while(right < nums.size() - 1 && nums[right] == nums[right + 1] ){
            ++right;
        }
        nums[left] = nums[right];
        ++left;
    }
    if(nums[nums.size() - 1] != nums[nums.size() - 2]){
        nums[left] = nums[nums.size() - 1];
        ++left;
    }
    return left;
}

int main() {
    vector<int> arr{1,1};
    removeDuplicates(arr);
    std::string str = "12312";
}
