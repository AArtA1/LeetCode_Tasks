#include <iostream>
#include <unordered_set>

using std::string,std::unordered_set;

int numJewelsInStones(string jewels, string stones) {
    unordered_set<char> symbols;
    for(auto ch : jewels){
        symbols.insert(ch);
    }
    int counter = 0;
    for(auto ch : stones){
        counter += symbols.find(ch) != symbols.end()?1:0;
    }
    return counter;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
