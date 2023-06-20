#include <iostream>
#include <string>

using std::string;

bool checkPalindrome(const string& s,int left,int right,int counter){
    if(counter > 1){
        return false;
    }
    while(left < right){
        if(s[left] == s[right]){
            ++left;
            --right;
        }
        else{
            return checkPalindrome(s,left+1,right,counter+1) || checkPalindrome(s,left,right-1,counter+1);
        }
    }
    return true;
}

bool validPalindrome(string s) {
    return checkPalindrome(s,0,s.size()-1,0);
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
