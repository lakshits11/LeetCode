static const auto speedup = []() -> int
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();
class Solution
{
public:
    string shortestCommonSupersequence(string &A, string &B)
    {
        int i = 0, j = 0;
        string res = "";
        for (char c : lcs(A, B))
        {
            while (A[i] != c && i < A.size())
                res += A[i++];
            while (B[j] != c && j < B.size())
                res += B[j++];
            res += c, i++, j++;
        }
        return res + A.substr(i) + B.substr(j);
    }

    vector<char> lcs(string &s1, string &s2)
    {
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; ++j)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        int lcsl = dp[n1][n2];

        vector<char> ans(lcsl);
        int i = n1, j = n2;
        while (i > 0 && j > 0)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                ans[lcsl - 1] = s1[i - 1];
                i--, j--, lcsl--;
            }
            else
            {
                if (dp[i - 1][j] > dp[i][j - 1])
                    i--;
                else
                    j--;
            }
        }
        return ans;
    }
};
