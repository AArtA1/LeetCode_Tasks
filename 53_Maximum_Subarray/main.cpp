#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::string,std::vector,std::unordered_map;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string,vector<string>> map;
    for(auto str : strs){
        auto x = str;
        sort(x.begin(),x.end());
        map[x].push_back(str);
    }
    vector<vector<string>> res;
    for(auto value : map){
        res.push_back(value.second);
    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
