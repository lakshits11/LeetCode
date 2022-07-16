class Solution {
private:
    const int mod = 1e9 + 7, moves[4][2] {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int findPaths(int m, int n, int maxMove, int r, int c) {
        auto outOfBounds = [&](int m, int n, int r, int c){return r < 0 || r >= m || c < 0 || c >= n;};
        uint dp[50][50][2]{};        
        for(int M = 1; M <= maxMove; M++)
            for(int i = 0; i < m; i++) 
                for(int j = 0, k; j < n; j++) 
                    for(k = 0, dp[i][j][M & 1] = 0; k < 4; k++) 
                        if(outOfBounds(m, n, i + moves[k][0], j + moves[k][1])) dp[i][j][M & 1]++;
                        else dp[i][j][M & 1] += dp[i + moves[k][0]][j + moves[k][1]][(M-1) & 1] % mod;
        return dp[r][c][maxMove & 1] % mod;
    }
};

