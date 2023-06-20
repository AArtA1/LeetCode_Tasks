#include <iostream>
#include <vector>
#include <string>

using std::string, std::cin, std::cout, std::vector;



// Time Complexity: O(n)
// Space Complexity: O(n)

void transform_string(string& s){
    for(int i = 0; i <= s.size();i+=2){
        s.insert(i,"#");
    }
}


string manacher_odd(string s) {
    int n = s.size();
    if(n == 1){
        return s;
    }
    if(n==2){
        return s[0] == s[n-1]?s:s.substr(0,1);
    }
    transform_string(s);
    n = s.size();
    int index = 0;
    vector<int> d(n, 1);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r)
            d[i] = std::min(r - i + 1, d[l + r - i]);
        while (i - d[i] >= 0 && i + d[i] < n && s[i - d[i]] == s[i + d[i]]){
            d[i]++;
        }
        if(d[i] > d[index]){
            index = i;
        }
        if (i + d[i] - 1 > r){
            l = i - d[i] + 1;
            r = i + d[i] - 1;
        }
    }
    auto res = s.substr(index - d[index] + 1, d[index]*2 - 1);
    string output;
    output.reserve(res.size() + output.size());
    std::copy_if(res.cbegin(),
                 res.cend(),
                 std::back_inserter(output),
                 [] (char ch){return ch != '#';});
    return output;
}

void solve(string s){
    int left = 0;
    int right = 0;
    int n = s.size();
    int max_index = 0;
    vector<int> d(n,1);
    for(int i = 1; i < n;++i){
        if(i < right){
            d[i] = std::min(right - i + 1,d[right + left - i]);
        }
        while(i - d[i] >= 0 && i + d[i] < n && s[i - d[i]] == s[i + d[i]]){
            ++d[i];
        }
        if(d[i] > d[max_index]){
            max_index = i;
        }
        if(i + d[i] - 1 > right){
            left = i - d[i] + 1;
            right = i + d[i] - 1;
        }
    }
}

int main() {
    string str = "abcdedcbahihabcdedcxyz";
    string str1 = "abcdefedghihgdefedcbz";
    string str2 = "abb";
    std::cout << manacher_odd(str2);
}
