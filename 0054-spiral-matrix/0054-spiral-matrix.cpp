class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int r1 = 0, r2 = m-1, c1 = 0, c2 = n-1;
        vector<int> res;
        while(r1<=r2 && c1<=c2)
        {
            for(int i=c1;i<=c2;i++)
                res.push_back(mat[r1][i]);
            for(int i=r1+1;i<=r2;i++)
                res.push_back(mat[i][c2]);
            if(r2>r1)
            for(int i=c2-1;i>=c1;i--)
                res.push_back(mat[r2][i]);
            if(c2>c1)
            for(int i=r2-1;i>=r1+1;i--)
                res.push_back(mat[i][c1]);
            r1++;r2--;
            c1++;c2--;
        }
        return res;
    }
};