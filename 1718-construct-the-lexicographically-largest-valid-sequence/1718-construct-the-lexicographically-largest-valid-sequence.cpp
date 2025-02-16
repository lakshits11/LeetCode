static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class Solution {
private:
    bool calc(int i, vector<int> &ans, vector<bool> &vis, int n)
    {
        if(i == ans.size()) return true;
        if(ans[i] != 0) return calc(i+1, ans, vis, n);
        else
        {
            for(int j=n;j>=1;j--)
            {
                if(vis[j]) continue;
                vis[j] = true;
                ans[i] = j;
                if(j == 1)
                {
                    if(calc(i+1, ans, vis, n)) return true;
                }
                else if(i+j < ans.size() && ans[i+j] == 0)
                {
                    ans[i+j] = j;
                    if(calc(i+1, ans, vis, n)) return true;
                    ans[i+j] = 0;
                }
                ans[i] = 0;
                vis[j] = false;
            }
        }
        return false;
    }

public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2*n-1, 0);
        vector<bool> vis(n+1, false);
        calc(0, ans, vis, n);
        return ans;
    }
};