class Solution {
public:
    int LCS(string &a, string &b)
    {
        int m = a.length();
        int n = b.length();
        int dp[m + 1][n + 1];

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

        return dp[m][n];
    }
    
    int minDistance(string word1, string word2) {
        ios_base::sync_with_stdio(0);
        int lcsl = LCS(word1, word2);
        return word1.length() + word2.length() - 2*lcsl;
    }
};