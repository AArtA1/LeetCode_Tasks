// Time: O(n)
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size() + s2.size()){
            return false;
        }

        bool table[s1.size() + 1][s2.size() + 1];
        table[0][0] = true;
        
        for(int i = 1; i <= s2.size();++i){
            table[0][i] = table[0][i-1] && s2[i-1] == s3[i-1];
        }

        for(int i = 1; i <= s1.size();++i){
            table[i][0] = table[i-1][0] && s1[i-1] == s3[i-1]; 
        }
        for(int i = 1; i <= s1.size();++i){
            for(int j = 1; j <= s2.size();++j){
                table[i][j] = (table[i-1][j] && s1[i-1] == s3[i+j - 1]) || (table[i][j-1] && s2[j-1] == s3[i+j-1]);
            }
        }
        return table[s1.size()][s2.size()];
    }
};