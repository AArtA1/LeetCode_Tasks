#include <iostream>
#include <vector>
#include <unordered_map>

using std::string;

int firstUniqChar(string s) {
    std::unordered_map<char,int> map;
    for(auto ch : s){
        ++map[ch];
    }
    for(int i = 0; i < s.size();++i){
        if(map[s[i]] == 1){
            return i;
        }
    }
    return -1;
}

int main() {

}
