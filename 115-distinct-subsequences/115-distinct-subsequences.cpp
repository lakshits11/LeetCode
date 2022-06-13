// class Solution
// {
// public:
//     int numDistinct(string s, string t)
//     {
//         int n = s.length(), m = t.length();
//         vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

//         for (int i = 0; i <= n; ++i) {
//             for (int j = 0; j <= m; ++j) {
//                 if (j == 0)
//                     dp[i][j] = 1;
//                 else if (i == 0 && j != 0)
//                     dp[i][j] = 0;
//                 else if (s[i - 1] == t[j - 1])
//                     dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
//                 else
//                     dp[i][j] = dp[i - 1][j];
//             }
//         }

//         return dp[n][m];
//     }
// };

#define ull unsigned long long
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        ios_base::sync_with_stdio(false);
        int n = s.length(), m = t.length();
        vector<vector<ull>> dp(n + 1, vector<ull>(m + 1, 0));

        dp[0][0]=1;
        for (int i = 1; i <= n; ++i)
        {
            dp[i][0] = 1;
            for (int j = 1; j <= m; ++j)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n][m];
    }
};