static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> t(begin(days), end(days));
        int dp[30] = {};
        for(int i = days.front(); i <= days.back(); ++i)
        {
            if(t.find(i) == t.end())
                dp[i%30] = dp[(i-1)%30];
            else
                dp[i%30] = min({
                    dp[(i-1)%30] + costs[0],
                    dp[max(0, i-7)%30] + costs[1],
                    dp[max(0, i-30)%30] + costs[2],
                });
        }
        return dp[days.back() % 30];
    }
};