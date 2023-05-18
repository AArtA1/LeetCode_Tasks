#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector,std::cin,std::cout,std::unordered_map;


// Time Complexity: O(n)
// Space Complexity: O (n)

vector<int> twoSum(vector<int>& nums,int target){
    vector<int> result(2);
    unordered_map<int,int> map;
    for(int i = 0; i < nums.size(); ++i){
        if(map.find(target - nums[i]) != map.end()){
            result[0] = map[target - nums[i]];
            result[1] = i;
            break;
        }
        map[nums[i]] = i;
    }
    return result;
}

int main() {
    auto nums = vector<int>{1,2,5,6,3,7};
    auto result = twoSum(nums,6);
    for(auto i : result){
        cout << i << " ";
    }
}
