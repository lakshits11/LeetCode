class Solution {
public:
    bool isMatch(string s2, string s1) {
        ios_base::sync_with_stdio(false);
        int n = s1.length(), m = s2.length();
        bool dp[n+1][m+1];
        
        dp[0][0] = true;
        for(int j=1;j<=m;j++)
            dp[0][j] = false;
        for(int i=1;i<=n;i++)
        {
            if(s1[i-1]=='*' && dp[i-1][0]==true)
                dp[i][0]=true;
            else
                dp[i][0]=false;
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                if (s1[i-1] == s2[j-1] || s1[i-1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if(s1[i-1]=='*')
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else
                    dp[i][j] = false;
            }
        }
        
        return dp[n][m];
    }
};