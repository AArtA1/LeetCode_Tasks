#include <iostream>
#include <vector>

using std::vector;

vector<int> searchRange(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int mid;
    int index;
    index = -1;
    while(left <= right){
        mid = left + (right - left)/2;
        if(nums[mid] == target){
            index = mid;
            break;
        }
        if(nums[mid] < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    if(index == -1){
        return {-1,-1};
    }
    int res1 = index,res2 = index;
    while(res1 >= 0 && nums[index] == nums[res1]){
        --res1;
    }
    while(res2 < nums.size() && nums[index] == nums[res2]){
        ++res2;
    }
    return {res1+1,res2-1};
}

int main() {
    vector<int> arr{1};
    searchRange(arr,1);
}
