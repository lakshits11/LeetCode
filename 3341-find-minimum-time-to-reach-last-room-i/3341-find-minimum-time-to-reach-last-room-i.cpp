class Solution {
public:
    int minTimeToReach(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minh;
        minh.push({0, 0, 0});
        g[0][0] = 0;
        int dir[5] = {-1, 0, 1, 0, -1};
        while (!minh.empty()) 
        {
            vector<int> curr = minh.top();
            minh.pop();
            int currTime = curr[0], r = curr[1], c = curr[2];
            if (currTime >= dp[r][c])
                continue;

            if (r == n - 1 && c == m - 1)
                return currTime;
            dp[r][c] = currTime;

            for (int i = 0; i < 4; i++) 
            {
                int nr = r + dir[i], nc = c + dir[i + 1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && dp[nr][nc] == INT_MAX) 
                {
                    int nextTime = max(g[nr][nc], currTime) + 1;
                    minh.push({nextTime, nr, nc});
                }
            }
        }
        return -1;
    }
};