class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[m-1][n-1]==1 || grid[0][0]==1)
            return 0;
        vector<vector<int>> dp(m,vector<int>(n,1));
        
        for(int i=1;i<m;i++){
            dp[i][0] = (grid[i][0]==1 || dp[i-1][0]==0) ? 0 : 1;
        }
        for(int j=1;j<n;j++){
            dp[0][j] = (grid[0][j]==1 || dp[0][j-1]==0) ? 0 : 1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(grid[i][j]==1)
                    dp[i][j]=0;
                else
                {
                    dp[i][j]=dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};