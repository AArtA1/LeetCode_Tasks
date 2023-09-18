// Time: O(n*m)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> costs(m,vector<int>(n,0));
        costs[0][0] = grid[0][0];
        for(int i = 1; i < m;++i){
            costs[i][0] = costs[i-1][0] + grid[i][0];
        }
        for(int j = 1; j < n;++j){
            costs[0][j] = costs[0][j-1] + grid[0][j];
        }

        for(int i = 1; i < m;++i){
            for(int j = 1; j < n;++j){
                costs[i][j] = std::min(costs[i-1][j],costs[i][j-1]) + grid[i][j];
            }
        }
        return costs[m-1][n-1];
    }
};