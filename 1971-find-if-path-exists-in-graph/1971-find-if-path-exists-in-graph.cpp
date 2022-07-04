class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
        ios_base::sync_with_stdio(false);
        if(src==dest)   return true;
        vector<vector<int>> adj(n);
        for(int i=0; i<edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int vis[n+1];
        for(int i=0;i<=n;i++)   vis[i]=0;
        queue<int> q;
        q.push(src);
        vis[src]=1;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(int x : adj[node])
            {
                if(x==dest)
                    return true;
                if(!vis[x]) {
                    vis[x]=1;
                    q.push(x);
                }
            }
        }
        return false;
    }
};
