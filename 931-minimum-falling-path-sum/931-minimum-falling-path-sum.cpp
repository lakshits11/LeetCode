class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid[0].size();
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j==0){
                    grid[i][j] += min(grid[i-1][j], grid[i-1][j+1]);
                }
                else if(j==n-1){
                    grid[i][j] += min(grid[i-1][j], grid[i-1][j-1]);
                }
                else{
                    grid[i][j] += min({grid[i-1][j-1], grid[i-1][j], grid[i-1][j+1]});
                }
            }
        }
        
        return *min_element(grid[n-1].begin(), grid[n-1].end());
    }
};