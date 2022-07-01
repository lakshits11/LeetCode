class Solution
{
public:
    void dfs(vector<vector<char>> &board, int i, int j, int m, int n, vector<vector<int>> &vis)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || vis[i][j] != 0)
            return;
        if (board[i][j] == 'O')
        {
            vis[i][j] = 2;
            dfs(board, i + 1, j, m, n, vis);
            dfs(board, i - 1, j, m, n, vis);
            dfs(board, i, j - 1, m, n, vis);
            dfs(board, i, j + 1, m, n, vis);
        }
        else
            vis[i][j] = 1;
    }

    void solve(vector<vector<char>> &board)
    {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int j = 0; j < n; j++)
        {
            if (board[0][j] == 'O')
                dfs(board, 0, j, m, n, vis);
            if (board[m - 1][j] == 'O')
                dfs(board, m - 1, j, m, n, vis);
        }
        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O')
                dfs(board, i, 0, m, n, vis);
            if (board[i][n - 1] == 'O')
                dfs(board, i, n - 1, m, n, vis);
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (vis[i][j] != 2)
                    board[i][j] = 'X';
            }
        }
    }
};