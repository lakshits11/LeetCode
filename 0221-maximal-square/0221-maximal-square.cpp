class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            dp[i][n - 1] = mat[i][n - 1]-'0';
        }
        for (int j = 0; j < n; j++) {
            dp[m - 1][j] = mat[m - 1][j]-'0';
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                if (mat[i][j] != '0') {
                    dp[i][j] =
                        min({dp[i + 1][j], dp[i][j + 1], dp[i + 1][j + 1]}) + 1;
                }
            }
        }
        cout<<"%%%%%%%%%%%%%%%%%%%\n";
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dp[i][j]);
            }
        }
        return ans*ans;
    }
};