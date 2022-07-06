// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
private:
    bool dfs(int node, int parent, vector<int> adj[], vector<int> &vis)
    {
        vis[node] = 1;
        for(int x : adj[node])
        {
            if(!vis[x])
            {
                if(dfs(x, node, adj, vis))
                    return true;
            }
            else if(x != parent)
                return true;
        }
        return false;
    }
public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int n, vector<int> adj[]) {
        vector<int> vis(n, 0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(dfs(i, -1, adj, vis))
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