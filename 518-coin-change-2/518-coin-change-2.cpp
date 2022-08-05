class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[amount+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int j=0;j<coins.size();j++)
        {
            for(int i=1;i<=amount;i++)
            {
                if(i>=coins[j])
                    dp[i] += (long long)dp[i-coins[j]];
            }
        }
        return dp[amount];
    }
};