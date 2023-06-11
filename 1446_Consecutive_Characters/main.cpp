#include <iostream>

using std::string;

int maxPower(string s) {
    int counter = 1;
    int max = 0;
    for(int i = 1; i < s.size(); ++i){
        if(s[i] == s[i-1]){
            ++counter;
        }
        else{
            max = std::max(max,counter);
            counter = 1;
        }
    }
    max = std::max(max,counter);
    return max;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
