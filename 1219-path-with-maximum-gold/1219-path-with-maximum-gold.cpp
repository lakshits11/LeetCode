static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();
class Solution
{
public:
    int dir[5] = {-1, 0, 1, 0, -1};
    int dfs(int x, int y, vector<vector<int>> &g)
    {
        int temp = g[x][y];
        g[x][y] = 0;
        int ans = 0;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i], ny = y + dir[i + 1];
            if (nx >= 0 && ny >= 0 && nx < g.size() && ny < g[0].size() && g[nx][ny] != 0)
                ans = max(ans, dfs(nx, ny, g));
        }
        g[x][y] = temp;
        return ans+temp;
    }

    int getMaximumGold(vector<vector<int>> &g)
    {
        int tg = 0;
        int m = g.size(), n = g[0].size();
        int cnz = 0;
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (g[i][j] != 0) cnz++;
                tg += g[i][j];
            }
        }
        if (cnz == m * n) return tg;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (g[i][j] != 0)
                    ans = max(ans, dfs(i, j, g));
                if (ans == tg) return ans;
            }
        }
        return ans;
    }
};