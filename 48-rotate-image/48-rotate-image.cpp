class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<=i;j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix.size()/2;j++)
            {
                swap(matrix[i][j], matrix[i][n-j-1]);
            }
            // cout<<"\n";
        }
    }
};