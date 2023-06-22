class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        ios_base::sync_with_stdio(false);
        int n = prices.size();
        int dp[4];
        dp[0] = dp[1] = dp[2] = dp[3] = 0;
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<2;++j)
            {
                if(j==0)
                    dp[0] = max(dp[2], -prices[i]+dp[3]);
                else
                    // Pay fee after you sell
                    dp[1] = max(dp[3], prices[i] - fee + dp[2]);
            }
            dp[2]=dp[0];
            dp[3]=dp[1];
        }
        return dp[0];
    }
};