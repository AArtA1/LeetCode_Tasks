#include <iostream>
#include <vector>

using std::string,std::vector;

int characterReplacement(string s, int k) {
    if (s.size() == 0) {
        return 0;
    }
    vector <int> arr(128);
    int beg = 0, largestCount = 0;
    for (int end = 0; end < s.size(); end++) {
        largestCount = std::max(largestCount, ++arr[s[end]]);
        if (end - beg + 1 - largestCount > k){
            arr[s[beg++]]--;
        }
    }
    return s.length() - beg;
}

int main() {
    string s = "ABCBDACBA";
    std::cout << characterReplacement(s,2);
}
