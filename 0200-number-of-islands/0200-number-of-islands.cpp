class Solution {
public:
    int count=0;
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        if(i<grid.size() && j<grid[0].size() && i>=0 && j>=0 )
        {
            if(grid[i][j]=='0')
                return;
            grid[i][j]='0';
            dfs(grid, i+1, j);
            dfs(grid, i-1, j);
            dfs(grid, i, j+1);
            dfs(grid, i, j-1);
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1'){
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};