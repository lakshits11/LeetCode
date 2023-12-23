static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class Solution {
public:
    int m, n;
    int dp[100][100][201];
    bool f(vector<vector<char>> &grid, int i, int j, int k)
    {
        if(i>=m || j>= n) return false;
        
        if(grid[i][j]=='(') k++;
        else k--;
        
        if(k<0) return false;
        
        if(i==m-1 && j==n-1) return k==0;
        
        if(dp[i][j][k] != -1) return dp[i][j][k];
        
        return dp[i][j][k] = f(grid, i+1, j, k) | f(grid, i, j+1, k);
        
    }
    
    bool hasValidPath(vector<vector<char>>& grid)
    {
        m = grid.size(), n = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return f(grid,  0, 0, 0);
    }
};