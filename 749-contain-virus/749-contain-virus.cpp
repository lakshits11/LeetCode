// By Lakshit Somani
#include <bits/stdc++.h>
using namespace std;

class cluster
{
public:
    set<pair<int, int>> c;  // set of cells that are contaminated
    set<pair<int, int>> uc; // set of cells that are next to this cluster and are uncontaminated
    int wcnt = 0;           // walls required to contain this structure
};

class Solution
{
private:
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &vis, cluster &cl)
    {
        if (i == grid.size() || i < 0 || j == grid[0].size() || j < 0 || vis[i][j] || grid[i][j] == -1)
            return;

        // if cell is uncontaminated then add to the uncontaminatd cells (uc) and increment wall cnt
        if (grid[i][j] == 0)
        {
            cl.wcnt++;
            cl.uc.insert({i, j});
            return;
        }

        // if current cell is contaminated add to contaminated and mark vis = true
        cl.c.insert({i, j});
        vis[i][j] = true;

        dfs(i + 1, j, grid, vis, cl);
        dfs(i - 1, j, grid, vis, cl);
        dfs(i, j + 1, grid, vis, cl);
        dfs(i, j - 1, grid, vis, cl);
    }

public:
    int containVirus(vector<vector<int>> &grid)
    {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (;;)
        {
            // visited matrix
            vector<vector<bool>> vis(n, vector<bool>(m));

            // comparator for priority queue to sort it according to size of uncontaminated cells in cluster
            auto comp = [](const cluster &a, cluster &b)
            {
                return a.uc.size() < b.uc.size();
            };

            priority_queue<cluster, vector<cluster>, decltype(comp)> pq(comp);

            // search for contaminated cell in grid
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (!vis[i][j] && grid[i][j] == 1)
                    {
                        cluster c;
                        dfs(i, j, grid, vis, c);
                        pq.push(c);
                    }
                }
            }

            // if size of priority queue is 0 the termination condition is reached ie all contaminated cells are contained.
            if (pq.size() == 0)
                break;
            
            // Get the biggest cluster
            // Make all cells in it to -1
            // Add the walls required to contain them
            cluster k = pq.top();
            pq.pop();
            for (auto x : k.c)
                grid[x.first][x.second] = -1;

            ans += k.wcnt;

            // For the rest of the cells, make their uncontaminated cells as contaminated
            while (!pq.empty())
            {
                cluster temp = pq.top();
                pq.pop();
                for (auto x : temp.uc)
                    grid[x.first][x.second] = 1;
            }
        }
        return ans;
    }
};