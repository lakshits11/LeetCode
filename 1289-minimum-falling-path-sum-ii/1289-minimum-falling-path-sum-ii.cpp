class Solution {
private:
    vector<vector<int>> dp;
    int f(vector<vector<int>> &grid, int i, int j,int toAvoid)
    {
        
        if(i>=grid.size())
            return 0;
        if(dp[i][j] != -1) return dp[i][j];
        // if(i==grid.size()-1)
        // {
        //     int mini = INT_MAX;
        //     for(int x = 0; x < grid[i].size(); x++)
        //     {
        //         if(x != toAvoid)
        //             mini = min(mini, grid[i][x]);
        //     }
        //     return dp[i][j] = (mini!=INT_MAX ? mini : grid[i][j]);
        // }
        int mini = INT_MAX;
        for(int x = 0; x < grid[i].size(); x++)
        {
            if(x!=toAvoid)
                mini = min(mini, grid[i][x]+f(grid, i+1, x,x));
        }
        return dp[i][j] = mini;
    }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        dp = vector<vector<int>>(grid.size(), vector<int>(grid[0].size(), -1));
        int ans = INT_MAX;
        for(int i = 0; i < grid[0].size(); i++)
            ans = min(ans, f(grid, 0,i,-1));
        return ans;
    }
};