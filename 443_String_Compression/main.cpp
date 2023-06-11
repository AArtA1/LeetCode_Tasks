#include <iostream>
#include <vector>

using std::vector;

int compress(vector<char> &chars) {
    int size = 0;
    int counter = 1;
    int iterator = 0;
    for (int i = 0; i < chars.size() - 1; ++i) {
        if (chars[i] == chars[i + 1]) {
            ++counter;
        } else {
            if (counter == 1) {
                chars[iterator++] = chars[i];
                ++size;
            } else {
                size += 1 + std::to_string(counter).size();
                chars[iterator++] = chars[i];
                auto s = std::to_string(counter);
                for (auto ch: s) {
                    chars[iterator++] = ch;
                }
            }
            counter = 1;
        }
    }
    if (counter == 1) {
        chars[iterator++] = chars[chars.size() - 1];
        ++size;
    } else {
        size += 1 + std::to_string(counter).size();
        chars[iterator++] = chars[chars.size() - 1];
        auto s = std::to_string(counter);
        for (auto ch: s) {
            chars[iterator++] = ch;
        }
    }
    return size;
}

int main() {
    vector<char> ch{'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    std::cout << compress(ch);
}
