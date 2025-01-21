static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();
class Solution {
public:
    long long gridGame(vector<vector<int>>& g) {
        long long top = accumulate(begin(g[0]), end(g[0]), 0ll);
        long long bottom = 0;
        long long res = LLONG_MAX;
        for(int i = 0; i < g[0].size(); ++i) 
        {
            top -= g[0][i];
            res = min(res, max(top, bottom));
            bottom += g[1][i];
        }
        return res;
    }
};