
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int minDeletions(string s) {
        int counter[26] = {},result = 0 ;
        unordered_set<int> used;
        for(auto ch : s){
            ++counter[ch - 'a'];
        }
        for(int i = 0; i < 26;++i){
            while(counter[i] > 0 && !used.insert(counter[i]).second){
                --counter[i];
                ++result;
            }
        }
        return result;
    }
};