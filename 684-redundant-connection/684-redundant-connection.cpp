class Solution
{
private:
    vector<int> parent, rankofElement;
    int findParent(int node)
    {
        if (parent[node] == -1)
            return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionFunction(int u, int v)
    {
        // u = findParent(u);
        // v = findParent(v);
        if (rankofElement[u] < rankofElement[v])
            parent[u] = v;
        else if (rankofElement[u] > rankofElement[v])
            parent[v] = u;
        else
        {
            parent[v] = u;
            rankofElement[u]++;
        }
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        parent.resize(n+1, -1);
        rankofElement.resize(n+1, 0);
        for (vector<int> &x : edges)
        {
            int u = findParent(x[0]);
            int v = findParent(x[1]);
            if (u != v)
                unionFunction(u, v);
            else
            {
                return {x[0], x[1]};
            }
        }
        return {};
    }
};