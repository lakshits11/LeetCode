class Solution {
public:    
    int maxProfit(int k, vector<int>& prices) {
        // ios_base::sync_with_stdio(false);
        int n = prices.size(), x = 2*k;
        int dp[x + 1];
        memset(dp, 0, sizeof(dp));
        
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int tr=x-1;tr>=0;tr--)
            {
                if(tr%2==0)
                    dp[tr] = max(-prices[ind] + dp[tr+1], dp[tr]);
                else
                    dp[tr] = max(prices[ind] + dp[tr+1], dp[tr]);
            }
        }
        
        return dp[0];
    }
};