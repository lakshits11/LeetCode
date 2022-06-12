class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
        int m = a.length();
        int n = b.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 or j == 0)
                    dp[i][j] = 0;
                else if (a[i - 1] == b[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        int i=m, j=n;
        string ans="";
        while(i>0 && j>0)
        {
            if(a[i-1]==b[j-1])
            {
                ans += a[i-1];
                i--;j--;
            }
            // Moving up, so basically we add the s1[i-1]
            else if(dp[i-1][j] > dp[i][j-1])
            {
                ans += a[i-1];
                i--;
            }
            else
            {
                ans+=b[j-1];
                j--;
            }
        }
        while(i>0){
            ans+=a[i-1];
            i--;
        }
        while(j>0){
            ans+=b[j-1];
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};