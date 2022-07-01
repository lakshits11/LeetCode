class Solution
{
private:
    int m, n;
    vector<vector<bool>> atlantic, pacific;
    vector<vector<int>> ans;

public:
    void dfs(vector<vector<int>> &mat, vector<vector<bool>> &vis, int i, int j)
    {
        if (vis[i][j])
            return;
        vis[i][j] = true;

        // If cell is reachable from both the cells, insert into final ans
        if (atlantic[i][j] && pacific[i][j])
            ans.push_back(vector<int>{i, j});

        // dfs from current cell only if height of next cell is greater
        if (i + 1 < m && mat[i + 1][j] >= mat[i][j])
            dfs(mat, vis, i + 1, j);
        if (i - 1 >= 0 && mat[i - 1][j] >= mat[i][j])
            dfs(mat, vis, i - 1, j);
        if (j + 1 < n && mat[i][j + 1] >= mat[i][j])
            dfs(mat, vis, i, j + 1);
        if (j - 1 >= 0 && mat[i][j - 1] >= mat[i][j])
            dfs(mat, vis, i, j - 1);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &mat)
    {
        if (mat.size() == 0)
            return ans;
        m = mat.size(), n = mat[0].size();
        atlantic = pacific = vector<vector<bool>>(m, vector<bool>(n, false));
        // perform dfs on all edge cells (ocean connected cells)
        for (int i = 0; i < m; i++)
            dfs(mat, pacific, i, 0), dfs(mat, atlantic, i, n - 1);
        for (int j = 0; j < n; j++)
            dfs(mat, pacific, 0, j), dfs(mat, atlantic, m - 1, j);
        return ans;
    }
};