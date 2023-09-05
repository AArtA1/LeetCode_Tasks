#include <iostream>


void removeExtraSpaces(std::string& s){
    int j = 0;
    int i;
    for(i = 0;i < s.size();){
        if(s[i] == ' '){
            while(i < s.size() && s[i] == ' ') ++i;
            s[j++] = ' ';
        }
        else{
            s[j++] = s[i++];
        }
    }
    s = s.substr(0,j);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
