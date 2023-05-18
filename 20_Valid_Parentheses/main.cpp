#include <iostream>
#include <stack>
#include <unordered_map>

using std::stack,std::string;

bool isValid(string s) {
    bool flag = true;
    std::stack<char> stack{};
    std::unordered_map<char, char> symbols{{'}', '{'}, {')', '('}, {']', '['}};
    for (auto item : s) {
        if (item == '{' || item == '[' || item == '(') {
            stack.push(item);
        } else {
            if (stack.top() != symbols[item]) {
                flag = false;
                break;
            } else {
                stack.pop();
            }
        }
    }
    return flag && stack.empty();
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
