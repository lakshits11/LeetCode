class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<int> onesRow(m, 0);
        // vector<int> zeroRow(m, 0);
        vector<int> onesCol(n, 0);
        // vector<int> zeroCol(n, 0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    onesRow[i]++;
                    onesCol[j]++;
                }
            }
        }
        
        // number of zeros in a row = total ints in a row(i.e. n) - no of ones in that row
        // same for cols
        // by this we saved some space
        vector<vector<int>> diff(m, vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                diff[i][j] = 2*onesRow[i] + 2*onesCol[j] - (m+n);
            }
        }
        return diff;
    }
};