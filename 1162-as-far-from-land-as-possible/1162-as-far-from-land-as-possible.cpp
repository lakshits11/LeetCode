class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        int maxi = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                    q.push({i, j});
            }
        }

        while (!q.empty())
        {
            pair<int, int> curr = q.front();
            q.pop();
            int dirs[5] = {0, -1, 0, 1, 0};
            for (int i = 0; i < 4; i++)
            {
                int nx = curr.first + dirs[i];
                int ny = curr.second + dirs[i + 1];
                if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == 0)
                {
                    q.push({nx, ny});
                    grid[nx][ny] = grid[curr.first][curr.second] + 1;
                    maxi = max(maxi, grid[nx][ny]);
                }
            }
        }

        return (maxi > 0 ? maxi - 1 : -1);
    }
};