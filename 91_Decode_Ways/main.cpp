#include <iostream>

using std::string;

int counter = 0;

void solve(string &s, int index){
    if(index >= s.size()){
        ++counter;
        return;
    }
    if(s[index] != '0'){
        solve(s,index+1);
    }
    if(s.size() - index >= 2 && (s[index] <= '2' && s[index+1] <= '6')){
        solve(s,index+2);
    }
}

int numDecodings(string s) {
    solve(s,0);
}

int main() {
    std::cout << numDecodings("12");
}
