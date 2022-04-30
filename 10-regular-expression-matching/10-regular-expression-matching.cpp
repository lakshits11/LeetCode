class Solution
{
public:
    bool dp(int i, int j, string &s, string &p)
    {
        bool ans;
        // If `j` reach end of pattern `p` then it fully matches if and only if `i` reach end of string `s`
        if (j == p.length())
            return (i == s.length());

        if (j + 1 < p.length() && p[j + 1] == '*')
        {
            ans = dp(i, j + 2, s, p); // match zero chars
            if (i < s.length() && (s[i] == p[j] || p[j] == '.'))
                ans = ans || dp(i + 1, j, s, p);
            return ans;
        }
        if (p[j] == '.' || i < s.length() && s[i] == p[j])
            return dp(i + 1, j + 1, s, p);

        return false;
    }

    bool isMatch(string s, string p)
    {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);
        return dp(0, 0, s, p);
    }
};