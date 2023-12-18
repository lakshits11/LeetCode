static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), INF = m + n;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(mat[i][j] == 0) continue;
                int top = INF, left = INF;
                if(i-1>=0) top=mat[i-1][j];
                if(j-1>=0) left=mat[i][j-1];
                mat[i][j] = min(top, left) + 1;
            }
        }
        
        for(int i=m-1;i>=0;--i)
        {
            for(int j=n-1;j>=0;--j)
            {
                if(mat[i][j]==0) continue;
                int bottom=INF, right=INF;
                if(i+1<m) bottom=mat[i+1][j];
                if(j+1<n) right=mat[i][j+1];
                mat[i][j] = min(min(right, bottom)+1, mat[i][j]);
            }
        }
        
        return mat;
    }
};