#include <iostream>
#include <vector>


// Time Complexity: O(n)
// Space Complexity: O(1)
std::vector<int> productExceptSelf(std::vector<int> &nums) {
    std::vector<int> output(nums.size());
    output[0] = 1;
    for(int i = 1; i < nums.size();++i){
        output[i] = nums[i-1] * output[i-1];
    }
    int right = 1;
    for(int i = nums.size() - 1; i >=0; --i){
        output[i] *= right;
        right *= nums[i];
    }
    return output;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
