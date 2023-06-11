#include <iostream>
#include <vector>
#include <unordered_set>

using std::vector;

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    std::unordered_set<int> set1,set2;
    for(int i = 0; i < nums1.size();++i){
        set1.insert(nums1[i]);
    }
    for(int i = 0; i < nums2.size();++i){
        set2.insert(nums2[i]);
    }
    vector<vector<int>> res(2);
    for(auto item : set1){
        if(set2.find(item) == set2.end()){
            res[0].push_back(item);
        }
    }
    for(auto item : set2){
        if(set1.find(item) == set1.end()){
            res[1].push_back(item);
        }
    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
