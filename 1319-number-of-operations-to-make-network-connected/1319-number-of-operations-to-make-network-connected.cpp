class Solution {
private:
    void dfs(int i, vector<int> adj[], vector<int> &vis)
    {
        // if(vis[i])  return;
        vis[i] = 1;
        for(int temp : adj[i])
        {
            if(!vis[temp])
            {
                dfs(temp, adj, vis);
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& cables) {
        int c = cables.size();
        if(c < n-1)
            return -1;
        vector<int> adj[n];
        for(vector<int> x : cables)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> vis(n, 0);
        int ans = 0;
        for(int i = 0; i< n; i++)
        {
            if(!vis[i])
            {
                ans++;
                dfs(i, adj, vis);
            }
        }
        return ans-1;
    }
};