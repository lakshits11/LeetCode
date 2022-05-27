class Solution {
public:
    int numberOfSteps(int num) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<int> dp(num+3);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3;i<=num;i++)
        {
            if(i%2==0)
                dp[i] = 1 + dp[i/2];
            else
                dp[i] = 1 + dp[i-1];
        }
        return dp[num];
    }
};