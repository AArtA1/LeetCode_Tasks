#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::vector, std::unordered_map;

vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> map1, map2, result;
    for (auto it: nums1) {
        ++map1[it];
    }
    for (auto it: nums2) {
        ++map2[it];
    }

    for (auto pair: map1) {
        result[pair.first] = std::min(pair.second, map2[pair.first]);
    }
    vector<int> res;
    for (auto pair: result) {
        int counter = 0;
        while (counter != pair.second) {
            res.push_back(pair.first);
            ++counter;
        }
    }
    return res;
}


// Second solution
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());

    vector<int>res;
    int n=nums1.size(),m=nums2.size();
    int i=0,j=0;
    while(i<n && j<m) {
        if(nums1[i]==nums2[j]) {
            res.push_back(nums1[i]);
            i++;
            j++;
        }
        else if(nums1[i]<nums2[j]) i++;
        else j++;
    }
    return res;
}


int main() {
    vector<int> arr{4, 9, 5};
    vector<int> arr2{9, 4, 9, 8, 4};
    intersect(arr, arr2);
}
