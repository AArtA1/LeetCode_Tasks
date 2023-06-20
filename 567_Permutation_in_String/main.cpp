#include <iostream>
#include <vector>

using std::vector, std::string;

bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) {
        return false;
    }
    vector<int> const_s1(128, 0);
    vector<int> temp(128, 0);
    for (int i = 0; i < s1.size(); ++i) {
        ++const_s1[s1[i]];
        ++temp[s2[i]];
    }
    if (const_s1 == temp) {
        return true;
    }
    for (int i = s1.size(); i < s2.size(); ++i) {
        --temp[s2[i - s1.size()]];
        ++temp[s2[i]];
        if (const_s1 == temp) {
            return true;
        }
    }
    return false;
}


int main() {
    std::string first = "ab";
    std::string second = "eidbaooo";
    std::cout << checkInclusion(first, second);
}
