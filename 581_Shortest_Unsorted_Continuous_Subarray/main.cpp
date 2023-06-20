#include <iostream>
#include <vector>

int findUnsortedSubarray(std::vector<int>& nums) {
    int max = nums[0];
    int right = -1;
    for(int i = 1; i < nums.size();++i){
        if(max > nums[i]){
            right = i;
        }
        else{
            max = nums[i];
        }
    }
    int min = nums[nums.size() - 1];
    int left = 0;
    for(int i = nums.size() - 1; i>=0; --i){
        if(min < nums[i]){
            left = i;
        }
        else{
            min = nums[i];
        }
    }
    return(right - left + 1);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
