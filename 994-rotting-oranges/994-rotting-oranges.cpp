class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int days = 0, total = 0, count = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]!=0)
                    total++;
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        
        int dir[5] = {0, -1, 0, 1, 0};
        while(!q.empty())
        {
            int qlen = q.size();
            count += qlen;
            while(qlen--)
            {
                pair<int, int> curr = q.front();
                q.pop();
                for(int i=0; i<4; i++)
                {
                    int nx = curr.first + dir[i];
                    int ny = curr.second + dir[i+1];
                    if(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == 1)
                    {
                        q.push({nx, ny});
                        grid[nx][ny] = 2;
                    }
                }
            }
            if(!q.empty())
                days++;
        }
        return (total==count ? days : -1);
    }
};