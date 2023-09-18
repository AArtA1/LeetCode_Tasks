// Time Complexity: O(n*m)
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(),m = word2.size();
        vector<vector<int>> arr(n+1, vector<int>(m+1));
        for(int i = 0; i <= n;++i){
            arr[i][0] = i;
        }
        for(int i = 0; i <= m;++i){
            arr[0][i] = i;
        }
        for(int i = 1; i <= n;++i){
            for(int j = 1; j <= m;++j){
                arr[i][j] = std::min(arr[i-1][j-1] + (word1[i-1]==word2[j-1]?0:1),std::min(arr[i-1][j],arr[i][j-1]) + 1);
            }
        }
        return arr[n][m];
    }
};