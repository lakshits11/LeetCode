// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:

bool dfs(int node, vector<int> &vis, vector<int> adj[], int parent)
    {
        vis[node] = 1;
        //cout<<"Marking node : "<<node<<"as visited\n";
        for (auto x : adj[node])
        {
          //  cout<<"At nei : "<<x<<endl;
            if (vis[x]==0)
            {
               // cout<<"Visiting it\n";
                if (dfs(x, vis, adj, node))
                    return true;
            }
            else if (x != parent)
            {
                
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
            if (vis[i] == 0 && adj[i].size()>0)
            {
               // cout<<"at node : "<<i<<endl;
                if (dfs(i, vis, adj, -1))
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