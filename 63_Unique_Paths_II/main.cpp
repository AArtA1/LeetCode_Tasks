// Time Complexity: O(m*n)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> arr(m,vector<int>(n,0));
        if(obstacleGrid[0][0] == 1){
            arr[0][0] = 0;
        }
        else{
            arr[0][0] = 1;
        }
        for(int i = 1; i < m;++i){
            if(obstacleGrid[i][0] == 1){
                arr[i][0] = 0;
            }
            else{
                arr[i][0] = arr[i-1][0];
            }
        }
        for(int j = 1; j < n;++j){
            if(obstacleGrid[0][j] == 1){
                arr[0][j] = 0;
            }
            else{
                arr[0][j] = arr[0][j-1];
            }
        }
        for(int i = 1; i < m;++i){
            for(int j = 1; j < n;++j){
                if(obstacleGrid[i][j] == 1){
                    arr[i][j] = 0;
                }
                else{
                    arr[i][j] = arr[i-1][j] + arr[i][j-1];
                }
            }
        }
        return arr[m-1][n-1];
    }
};