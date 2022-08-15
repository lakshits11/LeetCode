class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k)
    {
        int dir[5] = {-1, 0, 1, 0, -1};
        priority_queue<array<int, 4>, vector<array<int, 4>>, greater<array<int, 4>>> pq;
        vector<vector<int>> res;
        pq.push({0, grid[start[0]][start[1]], start[0], start[1]});
        grid[start[0]][start[1]] = 0;
        while(!pq.empty() && res.size() < k)
        {
            auto [dist, price, x, y] = pq.top();
            pq.pop();
            if(price >= pricing[0] && price <= pricing[1])
                res.push_back({x, y});
            for(int k = 0; k < 4; k++)
            {
                int x1 = x + dir[k], y1 = y + dir[k+1];
                if(x1 >= 0 && y1 >= 0 && x1 < grid.size() && y1 < grid[0].size() && grid[x1][y1] != 0)
                {
                    pq.push({dist+1, grid[x1][y1], x1, y1});
                    grid[x1][y1] = 0;
                }
            }
        }
        
        return res;
        
        
    }
};