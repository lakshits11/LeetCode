// https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/solutions/1661394/java-short-solution-based-on-topological-sort-which-leaves-just-loops
static const auto speedup = []() -> int {
   std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return 0;
}();
class Solution
{
public:
    int maximumInvitations(vector<int> &fav)
    {
        int n = fav.size();
        vector<int> indegree(n, 0);
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++)
        {
            int j = fav[i];
            ++indegree[j];
        }
        queue<int> q;
        for (int i = 0; i < n; ++i)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
                vis[i] = true;
            }
        }
        // dp[i] is the longest path leading to i
        vector<int> dp(n, 0);
        while (!q.empty())
        {
            int t = q.front();
            q.pop();
            int j = fav[t];
            dp[j] = max(dp[j], dp[t] + 1);
            if (--indegree[j] == 0)
            {
                vis[j] = true;
                q.push(j);
            }
        }

        // now remaining not visited nodes are all loops
        // check each loop's length
        int res = 0, res2 = 0;
        for (int i = 0; i < n; ++i)
        {
            if (vis[i] == false)
            {
                int len = 0;
                for (int j = i; vis[j] == false; j = fav[j])
                {
                    vis[j] = true;
                    ++len;
                }
                if (len == 2)
                    res2 += 2 + dp[i] + dp[fav[i]];
                else
                    res = max(res, len);
            }
        }
        return max(res, res2);
    }
};