#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 1)
            return false;
        if (i == grid.size() - 1)
            return true;
        grid[i][j] = 1;
        return dfs(grid, i + 1, j) || dfs(grid, i - 1, j) || dfs(grid, i, j + 1) || dfs(grid, i, j - 1);
    }

    bool canWalk(vector<vector<int>> &cells, int row, int col, int dayAt)
    {
        // Create grid at dayAt day
        vector<vector<int>> grid(row, vector<int>(col, 0));
        for (int i = 0; i < dayAt; i++)
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        for (int j = 0; j < col; j++)
        {
            if (dfs(grid, 0, j))
                return true;
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>> &cells)
    {
        ios_base::sync_with_stdio(false);
        int l = 1, r = cells.size(), ans = 0;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (canWalk(cells, row, col, mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return ans;
    }
};