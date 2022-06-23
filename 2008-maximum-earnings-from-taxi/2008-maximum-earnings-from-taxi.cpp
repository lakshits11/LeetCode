class Solution
{
public:
    long long maxTaxiEarnings(int n, vector<vector<int>> &rides)
    {
        ios_base::sync_with_stdio(false);
        vector<vector<pair<int, int>>> rideStartAt(n);
        for (auto &ride : rides)
        {
            int s = ride[0], e = ride[1], t = ride[2];
            rideStartAt[s].push_back({e, e - s + t});
        }

        vector<long long> dp(n + 1);
        for (int i = n - 1; i >= 1; i--)
        {
            for (auto &[e, d] : rideStartAt[i])
                dp[i] = max(dp[e] + d, dp[i]);
            dp[i] = max(dp[i], dp[i + 1]);
        }
        return dp[1];
    }
};