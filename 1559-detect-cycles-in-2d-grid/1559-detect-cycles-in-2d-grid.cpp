static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class Solution
{
public:
    bool containsCycle(vector<vector<char>> &g)
    {
        // main takeaway; parent nhi hona chahiye and already visited
        // we will use bfs
        int m = g.size(), n = g[0].size();
        int dir[5] = {-1, 0, 1, 0, -1};
        vector<bool> vis(m * n, false);
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!vis[i * n + j])
                {
                    queue<pair<pair<int, int>, pair<int, int>>> q;
                    q.push({{i, j}, {-1, -1}});
                    vis[i * n + j] = true;
                    while (!q.empty())
                    {
                        int x = q.front().first.first;
                        int y = q.front().first.second;
                        int px = q.front().second.first;
                        int py = q.front().second.second;
                        q.pop();
                        for (int k = 0; k < 4; ++k)
                        {
                            int nx = x + dir[k];
                            int ny = y + dir[k + 1];
                            if (nx >= 0 && ny >= 0 && nx < m && ny < n && g[nx][ny] == g[x][y])
                            {
                                if (!vis[nx * n + ny])
                                {
                                    vis[nx * n + ny] = true;
                                    q.push({{nx, ny}, {x, y}});
                                }
                                else if (nx != px && ny != py)
                                    return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
};