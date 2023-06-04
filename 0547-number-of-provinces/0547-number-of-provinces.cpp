class Solution
{
    vector<vector<int>> adj;
    vector<int> vis;
    void dfs(int u)
    {
        vis[u] = 1;
        for (auto &x : adj[u])
        {
            if (!vis[x])
            {
                dfs(x);
            }
        }
    }

    public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = (int)isConnected.size();
        adj.resize(n + 1);
        vis.resize(n + 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1)
                {
                    adj[i + 1].push_back(j + 1);
                    adj[j + 1].push_back(i + 1);
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                ans++;
                dfs(i);
            }
        }
        return ans;
    }
};