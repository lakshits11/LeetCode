// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    
    bool checkby_dfs(int prev,int node, vector<int> adj[], vector<int> &visited) 
  {
       visited[node]=1;
       for(auto u :adj[node])
       {
           if(!visited[u])
           {
              if(checkby_dfs(node,u,adj,visited))
              return true;
           }
           else if(u!=prev)
           return true;
       }
       return false;
   }
   bool isCycle(int V, vector<int> adj[])
   {
       vector<int> visited(V, 0);
       
       for(int i=0; i<V; i++)
       {
           if(visited[i] == 0)
           {
               if(checkby_dfs(-1,i, adj, visited))
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