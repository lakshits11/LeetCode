class Solution {
public:
    
    void dfs(vector<vector<int>>& grid, int i, int j, int &area)
    {
        if(i<grid.size() && j<grid[0].size() && i>=0 && j>=0){
        if(grid[i][j]==0)   return;
        grid[i][j]=0;
        area+=1;
        
        
            dfs(grid, i+1, j, area);
            dfs(grid, i-1, j, area);
            dfs(grid, i, j+1, area);
            dfs(grid, i, j-1, area);
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int maxArea = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    int area = 0;
                    dfs(grid, i, j, area);
                    maxArea = max(area, maxArea);
                }
            }
        }
        return maxArea;
    }
};