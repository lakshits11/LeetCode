class Solution
{
private:
    int maxLength = INT_MIN;
    void dfs(int node, vector<int> &dist, vector<int> &vis, vector<int> &dfsVis, vector<int> &adj, int l)
    {
        if (node != -1)
        {
            if (!vis[node])
            {
                vis[node] = 1;
                dfsVis[node] = 1;
                dist[node] = l;
                dfs(adj[node], dist, vis, dfsVis, adj, l + 1);
                dfsVis[node] = 0;
            }
            else if (dfsVis[node])
                maxLength = max(maxLength, l - dist[node]);
        }
    }

public:
    int longestCycle(vector<int> &adj)
    {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);
        int n = adj.size();
        vector<int> vis(n, 0);
        vector<int> dfsVis(n, 0);
        vector<int> dist(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
                dfs(i, dist, vis, dfsVis, adj, 0);
        }
        return (maxLength == INT_MIN ? -1 : maxLength);
    }
};