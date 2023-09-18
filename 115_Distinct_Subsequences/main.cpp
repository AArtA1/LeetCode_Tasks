// Time: O(n*m)
class Solution {
public:
    int numDistinct(string s, string t) {
        std::vector<std::vector<uint64_t>> counter(t.size()+1,std::vector<uint64_t>(s.size()+1));
        counter[0][0] = 1;
        for (int i = 1; i <= t.size(); ++i) {
            counter[i][0] = 0;
        }
        for (int i = 1; i <= s.size(); ++i) {
            counter[0][i] = 1;
        }
        for (int i = 1; i <= t.size(); ++i) {
            for (int j = 1; j <= s.size(); ++j) {
                if(t[i-1] == s[j-1]){
                    counter[i][j] = counter[i-1][j-1] + counter[i][j-1];
                }
                else{
                    counter[i][j] = counter[i][j-1];
                }
            }
        }
        return counter[t.size()][s.size()];
    }
};