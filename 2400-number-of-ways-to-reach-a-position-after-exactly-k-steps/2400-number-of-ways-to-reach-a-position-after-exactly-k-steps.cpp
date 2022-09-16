class Solution {
public:
    int numberOfWays(int s, int e, int k)
    {
        int dp[1001][1001] = {};
        int mod = 1e9+7;
        if(dp[1][1] == 0)
        {
            for(int k=1;k<=1000;k++)
            {
                dp[k][k] = 1;
                for(int i=0;i<k;i++)
                {
                    dp[k][i] = (dp[k-1][abs(i-1)] + dp[k-1][i+1])%mod;
                }
            }
        }
        return dp[k][abs(s-e)];
    }
};