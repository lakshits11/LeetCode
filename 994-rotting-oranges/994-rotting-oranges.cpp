class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        queue<pair<int, int>> q;
        // count is count of rotten oranges after doing bfs
        int total = 0, count = 0, days = 0;
        
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 2)
                    q.emplace(i, j);
                if(grid[i][j] != 0)
                    total++;
            }
        }
        
        const int dir[5] = {-1, 0, 1, 0, -1};
        
        while(!q.empty())
        {
            int qlen = q.size();
            count += qlen;
            for(int i = 0; i < qlen; i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int k = 0; k < 4; k++)
                {
                    int nx = x + dir[k];
                    int ny = y + dir[k+1];
                    if(nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size() && grid[nx][ny] == 1)
                    {
                        q.push({nx, ny});
                        grid[nx][ny] = 2;
                    }
                }
            }
            if(!q.empty())
                days++;
        }        
        // now finally we have to check if all the fresh oranges have converted into rotten or not.
        // that why we do total == count
        // if we dont do: we fail at this test case:
        // grid = [[2,1,1],[0,1,1],[1,0,1]]
        // bottom left corner orange never gets rotten since it is not in contact with any of the fresh orange.
        return (total == count) ? days : -1;
    }
};