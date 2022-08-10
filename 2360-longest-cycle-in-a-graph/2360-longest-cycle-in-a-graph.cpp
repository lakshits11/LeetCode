class Solution {
private:
    int maxLength = INT_MIN;
    void dfs(int node, vector<int> &dist, vector<bool> &vis, vector<bool> &extra, vector<int> &edges, int distance)
    {
        if(node != -1)
        {
            if(!vis[node])
            {
                vis[node] = true;
                extra[node] = true;
                dist[node] = distance;
                dfs(edges[node], dist, vis, extra, edges, distance + 1);
                extra[node] = false;
            }
            else if(extra[node])
            {
                maxLength = max(maxLength, distance-dist[node]);
            }
        }
    }
public:
    int longestCycle(vector<int>& edges)
    {
        int n = edges.size();
        vector<bool> vis(n, false);
        vector<bool> extra(n, false);
        vector<int> dist(n, 0);
        for(int i = 0; i < edges.size(); i++)
        {
            if(!vis[i])
                dfs(i, dist, vis, extra, edges, 0);
        }
        return (maxLength==INT_MIN) ? -1 : maxLength;
    }
};