class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> curr(m,grid[0][0]);
        for(int i=1;i<m;i++)
            curr[i] = curr[i-1]+grid[i][0];
        for(int j=1;j<n;j++){
            curr[0] += grid[0][j];
            for(int i=1;i<m;i++)
                curr[i] = min(curr[i-1], curr[i]) + grid[i][j];
        }
        return curr[m-1];
    }
};