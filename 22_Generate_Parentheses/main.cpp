#include <iostream>
#include <vector>

using std::vector, std::string;

void gen(const int &n, int counter_open, int counter_close, string s, vector<string> &arr) {
    if (counter_open + counter_close == 2 * n) {
        arr.push_back(s);
        return;
    }
    if (counter_open < n) {
        gen(n, counter_open + 1, counter_close, s + '(', arr);
    }
    if (counter_open > counter_close) {
        gen(n, counter_open, counter_close + 1, s + ')', arr);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> arr;
    gen(n, 0, 0, "", arr);
    return arr;
}


int main() {
    auto arr = generateParenthesis(5);
    for (auto item: arr) {
        std::cout << item << "\n";
    }
}
