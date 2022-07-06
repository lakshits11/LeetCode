// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends




class Solution
{
public:
    bool bfs(vector<int> adj[], vector<int> &vis, int node)
    {
        vis[node] = 1;
        // q stores parent, node
        queue<pair<int, int>> q;
        q.push({-1, node});
        while(!q.empty())
        {
            int parent = q.front().first;
            int temp = q.front().second;
            q.pop();
            for(int x : adj[temp])
            {
                if(!vis[x])
                {
                    vis[x] = 1;
                    q.push({temp, x});
                }
                else if(x != parent)
                    return true;
            }
        }
        return false;
    }
    bool isCycle(int n, vector<int> adj[])
    {
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                if (bfs(adj, vis, i))
                    return true;
            }
        }
        return false;
    }
};




// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends