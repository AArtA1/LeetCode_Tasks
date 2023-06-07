#include <iostream>
#include <unordered_map>

using std::string,std::unordered_map;

bool isSubsequence(string s, string t) {
    int i = 0, j = 0;
    while(j < t.size()){
        if(s[i] == t[j]){
            ++i;
            ++j;
        }
        else{
            ++j;
        }
    }
    if(i < s.size()){
        return false;
    }
    return true;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
