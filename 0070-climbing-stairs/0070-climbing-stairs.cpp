int dp[46];

static const auto speedup = []() -> int {
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        dp[3]=3;
        for(int i=4;i<=45;i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
    return 0;
}();

class Solution {
public:
    int climbStairs(int n) {
        // int dp[46];
        // dp[0]=1;
        // dp[1]=1;
        // dp[2]=2;
        // dp[3]=3;
        // for(int i=4;i<=n;i++)
        // {
        //     dp[i] = dp[i-1] + dp[i-2];
        // }
        return dp[n];
    }
};