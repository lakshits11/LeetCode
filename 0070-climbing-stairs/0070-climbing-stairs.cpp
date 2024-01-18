int dp[46];

static const auto speedup = []() -> int {
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<46;++i)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return 0;
}();

class Solution {
public:
    int climbStairs(int n) {
        return dp[n];
    }
};