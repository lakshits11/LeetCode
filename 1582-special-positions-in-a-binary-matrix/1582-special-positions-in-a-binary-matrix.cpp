class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int rows[101] = {0};
        int cols[101] = {0};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j])
                    ++rows[i],++cols[j];
            }
        }
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] && rows[i]==1 && cols[j]==1)
                    ++ans;
            }
        }
        return ans;
    }
};