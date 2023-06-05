#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using std::vector;

vector<int> topKFrequent(vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end());
    vector<std::pair<int,int>> res;
    int counter = 1;
    for(int i = 1; i < nums.size();++i){
        if(nums[i] == nums[i - 1]){
            ++counter;
        }
        else{
            res.push_back({counter, nums[i-1]});
            counter = 1;
        }
    }
    if(counter != 0){
        res.push_back({counter,nums[nums.size() - 1]});
    }
    std::sort(res.begin(), res.end(),[](std::pair<int,int> first, std::pair<int,int> second){return first.first <
            second.first;});
    int i = res.size() - k;
    vector<int> result;
    result.reserve(k);
    while( i != res.size()){
        result.push_back(res[i].second);
        ++i;
    }
    return result;
}


int main() {
    vector<int> arr{1,1,1,2,2,3};
    topKFrequent(arr,2);
}
