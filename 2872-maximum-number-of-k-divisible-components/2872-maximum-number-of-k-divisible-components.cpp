static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();
class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> al(n);
        vector<int> cnt(n);
        int res = 0;
        for(const auto &e : edges) 
        {
            al[e[0]].push_back(e[1]);
            al[e[1]].push_back(e[0]);
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            cnt[i] = al[i].size();
            if(cnt[i] < 2)
                q.push(i);
        }
        while(!q.empty())
        {
            int i = q.front();
            q.pop();
            --cnt[i];
            res += (values[i]%k==0);
            for(auto j : al[i])
            {
                if(cnt[j]!=0)
                {
                    values[j] += values[i]%k;
                    if(--cnt[j]==1)
                        q.push(j);
                }
            }
        }
        return res;
    }
};