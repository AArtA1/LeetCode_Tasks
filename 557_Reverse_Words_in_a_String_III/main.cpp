#include <iostream>
#include <stack>
#include <algorithm>

using std::stack, std::string;


string reverseWords(string s) {
    int last_index = 0;
    for (int j = 0; j < s.size(); ++j) {
        if (s[j] == ' ') {
            std::reverse(s.begin() + last_index, s.begin() + j);
            last_index = j + 1;
        }
    }
    std::reverse(s.begin() + last_index, s.end());
    return s;
}

int main() {
    std::cout << reverseWords("Let's take LeetCode contest");
}
