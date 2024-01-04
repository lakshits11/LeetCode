#define ull unsigned long long
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);
        int n = s.length(), m = t.length();
        vector<ull> dp(m + 1, 0);

        dp[0]=1;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = m; j >= 1; j--)
            {
                if (s[i - 1] == t[j - 1])
                    dp[j] += dp[j - 1];
            }
        }

        return dp[m];
    }
};