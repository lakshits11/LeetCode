static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class Solution {
    public:
    int dir[5] = {-1, 0, 1, 0, -1};

    void dfs(vector<vector<int>> &grid, int i, int j)
    {
        grid[i][j]=0;
        for(int k=0;k<4;++k)
        {
            int ni=i+dir[k], nj=j+dir[k+1];
            if(ni>=0 && nj>=0 && ni<grid.size() && nj<grid[0].size() && grid[ni][nj]==1){
                dfs(grid, ni, nj);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size(), n = grid[0].size();

        for(int i=0;i<m;i++)
        {
            if(grid[i][0]==1)
                dfs(grid, i, 0);
            if(grid[i][n-1]==1)
                dfs(grid, i, n-1);
        }

        for(int j=0;j<n;j++)
        {
            if(grid[0][j]==1)
                dfs(grid,0,j);
            if(grid[m-1][j] == 1)
                dfs(grid, m-1, j);
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)++ans;
            }
        }
        return ans;
    }
};