class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> ans = img;
        int m = img.size(), n = img[0].size();
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                int sum=0;
                int count=0;
                
                for(int x=i-1;x<=i+1;++x)
                {
                    for(int y=j-1;y<=j+1;++y)
                    {
                        if(x>=0 && y>=0 && x<m && y<n)
                        {
                            sum += img[x][y];
                            ++count;
                        }
                    }
                }
                
                ans[i][j] = sum/count;
            }
        }
        return ans;
    }
};