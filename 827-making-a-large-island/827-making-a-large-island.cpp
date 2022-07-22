// By Lakshit Somani
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int n;
    const int dir[5] = {-1, 0, 1, 0, -1};
    bool valid(int x, int y)
    {
        return x >= 0 && y >= 0 && x < n && y < n;
    }

    int dfs(vector<vector<int>> &grid, int x, int y, int index)
    {
        int area = 0;
        grid[x][y] = index;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i], ny = y + dir[i + 1];
            if (valid(nx, ny) && grid[nx][ny] == 1)
                area += dfs(grid, nx, ny, index);
        }
        return area + 1;
    }

public:
    int largestIsland(vector<vector<int>> &grid)
    {
        n = grid.size();
        int res = 0, index = 2;
        unordered_map<int, int> area;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    area[index] = dfs(grid, i, j, index);
                    res = max(res, area[index++]);
                }
            }
        }

        // Traverse very 0 cell and count biggest island it can connect
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    unordered_set<int> seen = {};
                    int curr = 1;
                    for (int x = 0; x < 4; x++)
                    {
                        int ni = i + dir[x], nj = j + dir[x + 1];
                        if (valid(ni, nj))
                        {
                            index = grid[ni][nj];
                            if (index > 1 && seen.count(index) == 0)
                            {
                                seen.insert(index);
                                curr += area[index];
                            }
                        }
                    }
                    res = max(res, curr);
                }
            }
        }

        return res;
    }
};