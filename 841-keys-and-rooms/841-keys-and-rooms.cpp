class Solution {
private:
    int ans = 1;
    void dfs(int node, vector<int> &vis, vector<vector<int>> &rooms)
    {
        vis[node] = 1;
        for(int x : rooms[node])
        {
            if(!vis[x])
            {
                ans++;
                dfs(x, vis, rooms);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n,0);
        dfs(0, vis, rooms);
        return ans == n;
    }
};