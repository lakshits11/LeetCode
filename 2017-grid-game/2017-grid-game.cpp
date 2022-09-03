class Solution {
public:
    long long gridGame(vector<vector<int>>& g) {
        long long top = accumulate(g[0].begin(), g[0].end(), 0ll);
        long long bottom = 0, res = LLONG_MAX;
        for(int i = 0; i < g[0].size(); i++)
        {
            top -= g[0][i];
            long long x = max(top, bottom);
            res = min(res, x);
            bottom += g[1][i];
        }
        return res;
    }
};