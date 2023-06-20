#include <iostream>
#include <vector>
#include <unordered_map>


using std::vector;

int subarraysDivByK(vector<int>& nums, int k) {
    std::unordered_map<int,int> map;
    map[0] = 1;
    int prefix = 0;
    int result = 0;
    for(auto it : nums){
        prefix = (prefix + it % k + k) % k;
        result += map[prefix]++;
    }
    return result;
}

int main() {
    vector<int> arr{5,5,5};

    std::cout << subarraysDivByK(arr,5);
}
