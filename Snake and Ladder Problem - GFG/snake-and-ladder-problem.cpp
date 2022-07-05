// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int bfs(int src, int dest, vector<vector<int>> &adj)
    {
        vector<int> dist(dest+1, INT_MAX);
        dist[src] = 0;
        queue<int> q;
        q.push(src);
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(int x : adj[node])
            {
                if(dist[node]+1 < dist[x])
                {
                    dist[x] = dist[node]+1;
                    q.push(x);
                }
            }
        }
        
        return dist[dest];
    }
public:
    int minThrow(int N, int arr[]){
        vector<vector<int>> adj(31);
        int board[40] = {};
        for(int i=0;i<N;i++)
        {
            board[arr[2*i]] = arr[2*i+1]-arr[2*i];
        }
        for(int i=1;i<=30;i++)
        {
            for(int dice = 1; dice<=6; dice++)
            {
                int j = i+dice;
                j += board[j];
                if(j<=31)
                {
                    adj[i].push_back(j);
                }
            }
        }
        return bfs(1, 30, adj);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends