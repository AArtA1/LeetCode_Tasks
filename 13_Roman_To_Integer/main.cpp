#include <iostream>
#include <unordered_map>

int romanToInt(std::string s) {
    std::unordered_map<char, int> unorderedMap{{'I', 1},
                                               {'V', 5},
                                               {'X', 10},
                                               {'L', 50},
                                               {'C', 100},
                                               {'D', 500},
                                               {'M', 1000}};
    int sum = 0;
    int i;
    for (i = s.size() - 1; i > 0; --i) {
        if ((s[i - 1] == 'I' && (s[i] == 'V' || s[i] == 'X')) ||
            (s[i - 1] == 'X' && (s[i] == 'L' || s[i] == 'C')) ||
            (s[i - 1] == 'C' && (s[i] == 'D' || s[i] == 'M'))) {
            sum += unorderedMap[s[i]] - unorderedMap[s[i - 1]];
            --i;
            continue;
        }
        sum += unorderedMap[s[i]];
    }
    ++i;
    if (!((s[i - 1] == 'I' && (s[i] == 'V' || s[i] == 'X')) ||
          (s[i - 1] == 'X' && (s[i] == 'L' || s[i] == 'C')) ||
          (s[i - 1] == 'C' && (s[i] == 'D' || s[i] == 'M')))) {
        sum += unorderedMap[s[i - 1]];
    }
    return sum;
}


int main() {
    std::string str = "III";
    std::cout << romanToInt(str);
    return 0;
}
