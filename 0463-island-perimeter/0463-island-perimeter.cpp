// By Lakshit Somani
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    res += 4;
                    if (i != 0 and grid[i - 1][j] == 1)
                        res -= 2;
                    if (j != 0 and grid[i][j - 1] == 1)
                        res -= 2;
                }
            }
        }
        return res;
    }
};