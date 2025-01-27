static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();
class Solution {
public:
    // u[x] contains all persons which are richer than x
    // that is if richer array contains [a,b] i.e. a is richer than b, then u[b] will contain a
    unordered_map<int, vector<int>> richer2;

    vector<int> res;

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        for(vector<int> &x : richer)
            richer2[x[1]].push_back(x[0]);
        res = vector<int>(quiet.size(), -1);
        for(int i = 0; i < quiet.size(); ++i)
            dfs(i, quiet);
        return res;
    }

    int dfs(int i, vector<int> &quiet)
    {
        if(res[i]>=0) return res[i];
        res[i] = i;
        for(int j : richer2[i])
        {
            if(quiet[dfs(j, quiet)] < quiet[res[i]])
                res[i] = res[j];
        }
        return res[i];
    }
};