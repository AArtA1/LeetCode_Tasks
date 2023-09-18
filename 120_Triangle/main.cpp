class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> sums(n);
        sums[0] = vector<int>(triangle[0]);
        for(int i = 1; i < n;++i){
            sums[i] = vector<int>(i+1);
            sums[i][0] = sums[i-1][0] + triangle[i][0];
            sums[i][i] = sums[i-1][i-1] + triangle[i][i];
            for(int j = 1; j < i;++j){
                sums[i][j] = std::min(sums[i-1][j-1],sums[i-1][j]) + triangle[i][j];
            }
        }
        int min = INT32_MAX;
        for(auto item : sums[n-1]){
            min = std::min(min,item);
        }
        return min;
    }
};