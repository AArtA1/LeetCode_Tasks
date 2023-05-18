#include <iostream>
#include <vector>

using std::string, std::cin, std::cout, std::vector;

// Time Complexity: O(n)
// Space Complexity: O(n)


string findPalindrom(string s){
    auto n = s.length();
    vector<int> h(n);
    auto C = 0, R = 0; // центр и радиус или крайний правый палиндром
    auto besti = 0, bestj = 0; // центр и радиус самого длинного палиндрома
    int j;
    for(int i = 0 ; i < n;++i){
        if(i < C + R){
            j = h[C-(i-C)];
            if(j < C + R - i){
                h[i] = j;
                continue;
            }
            else{
                if( j > C + R - i){
                    h[i] = C + R - i;
                    continue;
                }
            }
        }
        else{
            j = 0;
        }
        while (i - j > 0 && i + j < n-1 && s[i-j-1] == s[i+j+1]){
            j += 1;
        }
        h[i] = j;
        if(j > bestj){
            besti = i;
            bestj = j;
        }
        if(i + j > C + R){
            C = i;
            R = j;
        }
    }
    return s.substr(besti - bestj,bestj*2 + 1);
}

int main() {
    string str = "abcdedcbahihabcdedcxyz";
    string str1 = "abcdefedghihgdefedcbz";
    std::cout << findPalindrom(str1);
}
