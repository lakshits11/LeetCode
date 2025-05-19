class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ans = 0;
        for(int i=0;i<n;i++) 
        {
            dp[0][i]=mat[0][i];
            ans += dp[0][i];
        }
        for(int j=1;j<m;j++) 
        {
            dp[j][0] = mat[j][0];
            ans += dp[j][0];
        }

        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(mat[i][j])
                {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    ans += dp[i][j];
                }
            }
        }

        // for(auto x : dp)
        // {
        //     for(auto y : x)
        //     {
        //         cout << y << " ";
        //     }
        //     cout << "\n";
        // }
        return ans;
    }
};