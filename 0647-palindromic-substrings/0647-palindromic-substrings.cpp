static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int count = 0;
        for (int k = 0; k < n; k++) 
        {
            for (int i = 0, j = k; j < n; i++, j++) 
            {
                if (k == 0) {
                    dp[i][j] = true;
                    count++;
                } 
                else if (k == 1) {
                    dp[i][j] = (s[i] == s[j]);
                    count += (s[i] == s[j]);
                } 
                else {
                    if (s[i] == s[j]) 
                    {
                        dp[i][j] = dp[i + 1][j - 1];
                        count += (dp[i][j]==true);
                    }
                    else
                        dp[i][j] = false;
                }
            }
        }
        return count;
    }
};