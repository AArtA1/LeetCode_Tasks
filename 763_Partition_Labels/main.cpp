#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector,std::string;

vector<int> partitionLabels(string s) {
    std::unordered_map<char,int> map;
    for(int i = 0; i < s.size();++i){
        map[s[i]] = i;
    }

    int max = 0;
    int prev = -1;
    vector<int> res;
    for(int i = 0; i < s.size();++i){
        max = std::max(max,map[s[i]]);
        if(max == i){
            res.push_back(i - prev);
            prev = max;
        }
    }
    return res;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
