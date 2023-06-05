#include <iostream>
#include <unordered_map>

using std::string;

bool isAnagram(string s, string t) {
    std::unordered_map<char, int> first, second;
    if (s.size() != t.size()) {
        return false;
    }
    for (int i = 0; i < s.size(); ++i) {
        ++first[s[i]];
        ++second[t[i]];
    }
    for (int i = 0; i < 26; ++i) {
        if (first['a' + i] != second['a' + i]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::cout << isAnagram("aboba", "bobaa");
}
