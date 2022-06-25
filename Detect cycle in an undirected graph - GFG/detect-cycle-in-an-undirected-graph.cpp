// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
public:
    bool bfs(int node, vector<int> adj[], vector<int> &vis)
    {
        vis[node] = 1;
        queue<pair<int, int>> q;
        q.push({node, -1});
        while (!q.empty())
        {
            int t = q.front().first;
            int prev = q.front().second;

            q.pop();
            for (int x : adj[t])
            {
                if (!vis[x])
                {
                    vis[x] = 1;
                    q.push({x, t});
                }
                // it means node is already visited and
                // node's (here it means => x's) parent is
                // not the prev node we stored
                else if (prev != x)
                    return true;
            }
        }
        return false;
    }

    bool isCycle(int n, vector<int> adj[])
    {
        vector<int> vis(n + 1, 0);
        for (int i = 1; i < n; i++)
        {
            if (!vis[i])
                if (bfs(i, adj, vis))
                    return true;
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