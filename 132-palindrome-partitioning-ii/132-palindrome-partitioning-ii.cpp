class Solution {
    
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        vector<vector<bool>> pal(n, vector<bool>(n, false));
        
        dp[n] = 0;
        
        for(int i = n - 1; i >= 0; i--)
        {
            int minCost = INT_MAX;
            for(int j = i; j < s.size(); j++)
            {
                // This condition checks for palindrome
                if(s[i] == s[j] && (j - i <= 2 || pal[i+1][j-1]))
                {
                    pal[i][j] = true;
                    int cost = 1 + dp[j+1];
                    minCost = min(minCost, cost);
                }
            }
            dp[i] = minCost;
        }
        
        return dp[0] - 1;

    }
};