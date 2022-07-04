class Solution
{
private:
    void dfs(vector<vector<int>> &graph, vector<vector<int>> &res, vector<int> &path, vector<bool> &vis, int i, int n)
    {
        path.push_back(i);
        vis[i] = true;
        if (i == n - 1)
            res.push_back(path);
        else
        {
            for (int x : graph[i])
            {
                if (vis[x] == false)
                    dfs(graph, res, path, vis, x, n);
            }
        }
        vis[i] = false;
        path.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
    	ios_base::sync_with_stdio(false);
        int n = graph.size();
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> vis(n, false);
        dfs(graph, res, path, vis, 0, n);
        return res;
    }
};
