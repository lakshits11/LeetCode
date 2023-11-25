class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        if(grid[0][0] || grid.back().back()) return -1;
        int dir[5] = {-1,0,1,0,-1};
        int diag[5] = {1, -1,-1,1,1};
        
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({0,0});
        grid[0][0] = 1;
        int dist = 1;
        while(!q.empty())
        {
            int qlen = q.size();
            while(qlen--)
            {
                pair<int, int> node = q.front();
                q.pop();
                int x = node.first, y = node.second;
                if(x==m-1 && y==n-1) return dist;
                for(int k = 0; k < 4; k++)
                {
                    int nx = x+dir[k], ny = y+dir[k+1];
                    if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny] != 1)
                    {
                        q.push({nx, ny});
                        grid[nx][ny] = 1;
                    }
                }
                for(int k = 0; k < 4; k++)
                {
                    int nx = x+diag[k], ny = y+diag[k+1];
                    if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny] != 1)
                    {
                        q.push({nx, ny});
                        grid[nx][ny] = 1;
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};