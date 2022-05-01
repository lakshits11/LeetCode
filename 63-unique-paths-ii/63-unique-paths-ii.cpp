class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int w= grid[0].size();
        vector<int> dp(w);
        dp[0]=1;
        
        for(auto row : grid)
        {
            for(int j=0;j<w;j++)
            {
                if(row[j]==1)
                    dp[j]=0;
                else if(j>0)
                    dp[j] += dp[j-1];
            }
        }
        return dp[w-1];
    }
};