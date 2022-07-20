class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int dir[5] = {-1,0,1,0,-1};
        deque<pair<int, int>> q;
        q.push_front({0,0});
        dist[0][0] = 0;
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop_front();
            for(int i=0; i<4; i++)
            {
                int nx = x + dir[i];
                int ny = y + dir[i+1];
                if(nx >= 0 && ny >= 0 && nx < m && ny < n && !vis[nx][ny])
                {
                    vis[nx][ny] = true;
                    dist[nx][ny] = dist[x][y] + (grid[nx][ny]==1);
                    if(grid[nx][ny]==1)
                        q.push_back({nx,ny});
                    else q.push_front({nx,ny});
                }
            }
        }
        return dist[m-1][n-1];
    }
};