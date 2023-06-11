#include <iostream>
#include <vector>
#include <cmath>

using std::vector;


// Time Complexity: O(n)
// Space Complexity: O(1) without result array
vector<int> sortedSquares(vector<int>& nums) {
    auto right_it = std::lower_bound(nums.begin(),nums.end(),0);
    auto left_it = right_it - 1;
    vector<int> res;
    while(left_it != nums.begin() - 1 || right_it != nums.end()){
        if(left_it == nums.begin() - 1){
            res.push_back(pow(*right_it,2));
            ++right_it;
            continue;
        }
        if(right_it == nums.end()){
            res.push_back(pow(*left_it,2));
            --left_it;
            continue;
        }
        if(abs(*left_it) > *right_it){
            res.push_back(pow(*right_it,2));
            ++right_it;
        }
        else{
            res.push_back(pow(*left_it,2));
            --left_it;
        }
    }
    return res;
}
int main() {
    vector<int> arr{-1};
    sortedSquares(arr);
}
