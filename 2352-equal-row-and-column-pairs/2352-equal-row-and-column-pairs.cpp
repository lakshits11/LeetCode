class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size(), ans=0;
        // for(int i=0;i<n;i++)    sort(grid[i].begin(), grid[i].end());
        vector<vector<int>> orig = grid;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                swap(grid[i][j], grid[j][i]);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i]==orig[j])
                    ans++;
            }
            
        }
        return ans;
    }
};