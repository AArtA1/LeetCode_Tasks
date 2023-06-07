#include <iostream>
#include <vector>
#include <set>

using std::vector,std::string;


// Time Complexity: O(n)
// Space Complexity: O(1)
vector<int> findAnagrams(string s, string p) {
    if(s.size() < p.size()){
        return {};
    }
    std::vector<int> s_arr(26,0),p_arr(26,0);
    for(int i = 0; i < p.size();++i){
        ++s_arr[s[i] - 'a'];
        ++p_arr[p[i] - 'a'];
    }
    vector<int> res;
    if(s_arr == p_arr){
        res.push_back(0);
    }
    for(int i = p.size(); i < s.size();++i){
        ++s_arr[s[i] - 'a'];
        --s_arr[s[i - p.size()] - 'a'];
        if(s_arr == p_arr){
            res.push_back(i - p.size() + 1);
        }
    }
    return res;
}


int main() {
    string first = "cbaebabacd";
    string second = "abc";
    findAnagrams(first,second);
}
