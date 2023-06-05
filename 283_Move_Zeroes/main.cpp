#include <iostream>
#include <vector>

using std::vector;

void moveZeroes(vector<int> &nums) {
    int counter = 0;
    for (int i = 0; i < nums.size() - counter;) {
        if (nums[i] == 0) {
            nums.erase(nums.begin() + i);
            ++counter;
            nums.push_back(0);
        }
        else{
            ++i;
        }
    }
}
// Second;

void moveZeroes(vector<int>& nums) {
    int start=0,n=nums.size(); //Step 1
    for(int i=0;i<nums.size();i++){  //Step 2
        if(nums[i]!=0) nums[start++]=nums[i];
    }
    while(start<n) nums[start++]=0; //Step 3
}

int main() {
    vector<int> array{0,0,1};
    moveZeroes(array);
    std::cout << 1;
}
