class Solution
{
private:
    void dfs(int node, vector<int> &dist, vector<bool> &vis, vector<int> &edges, int currDistance)
    {
        if (node != -1 && !vis[node])
        {
            dist[node] = currDistance;
            vis[node] = true;
            dfs(edges[node], dist, vis, edges, currDistance + 1);
        }
    }

public:
    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        int n = edges.size();

        vector<int> dist1(n, -1);
        vector<int> dist2(n, -1);

        vector<bool> vis(n, false);

        dfs(node1, dist1, vis, edges, 0);

        fill(vis.begin(), vis.end(), false);

        dfs(node2, dist2, vis, edges, 0);
        int ans = n;
        int result = -1;
        for (int i = 0; i < n; i++)
        {
            if (dist1[i] != -1 && dist2[i] != -1 && max(dist1[i], dist2[i]) < ans)
            {
                ans = max(dist1[i], dist2[i]);
                result = i;
            }
        }
        return result;
    }
};