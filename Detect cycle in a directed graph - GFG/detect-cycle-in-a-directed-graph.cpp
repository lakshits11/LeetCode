// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    
    bool checkCycle(int node, vector<int> adj[], int vis[], int dfsVis[])
    {
        vis[node] = 1;
        dfsVis[node] = 1;
        for(int x : adj[node])
        {
            if(!vis[x]) {
                if(checkCycle(x,adj,vis,dfsVis))
                    return true;
            }
            else if(dfsVis[x])
                return true;
        }
        dfsVis[node] = 0;
        return false;
    }
    
    bool isCyclic(int n, vector<int> adj[]) {
        int vis[n], dfsVis[n];
        memset(vis, 0, sizeof(vis));
        memset(dfsVis, 0, sizeof(dfsVis));
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(checkCycle(i, adj, vis, dfsVis))
                    return true;
            }
        }
        
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends