class Solution {
    public:
    void dfs(int s, vector<vector<int>> &adj, vector<int> &vis)
    {
        vis[s]=1;
        for(int i : adj[s])
        {
            if(!vis[i])
            {
                dfs(i, adj, vis);
            }
        } 
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<rooms.size();i++)
        {
            for(int j=0;j<rooms[i].size();j++)
            {
                adj[i].push_back(rooms[i][j]);
            }
        }
        vector<int> vis(n,0);
        dfs(0, adj, vis);
        for(int i:vis){if(i==0) return false;}
        return true;
    }
};