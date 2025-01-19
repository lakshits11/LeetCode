static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class Solution {
public:
    typedef pair<int, pair<int, int>> PP;
    int trapRainWater(vector<vector<int>>& hm) {
        int m = hm.size(), n = hm[0].size();
        priority_queue<PP, vector<PP>, greater<>> pq;
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        // add boundary cells to pq
        for (int row = 0; row < m; row++) {
            for (int col : {0, n - 1}) {
                pq.push({hm[row][col], {row, col}});
                vis[row][col] = true;
            }
        }
        for (int j = 0; j < n; j++) {
            pq.push({hm[0][j], {0, j}});
            vis[0][j] = true, vis[m - 1][j] = true;
            pq.push({hm[m - 1][j], {m - 1, j}});
        }
        int water = 0;

        int dir[] = {-1, 0, 1, 0, -1};
        while (!pq.empty()) {
            PP p = pq.top();
            pq.pop();
            int ht = p.first;
            int x = p.second.first;
            int y = p.second.second;

            // find neighbours
            for (int i = 0; i < 4; i++) {
                int nx = x + dir[i];
                int ny = y + dir[i + 1];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n && !vis[nx][ny]) {
                    water += max(ht - hm[nx][ny], 0);
                    pq.push({max(ht, hm[nx][ny]), {nx, ny}});
                    vis[nx][ny] = true;
                }
            }
        }

        return water;
    }
};