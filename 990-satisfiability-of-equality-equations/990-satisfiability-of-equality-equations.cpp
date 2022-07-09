class DSU
{
public:
    vector<int> parent, rank;
    DSU(int n)
    {
        parent.resize(n, -1);
        rank.resize(n, 1);
    }
    int findParent(int u)
    {
        if (parent[u] == -1)
            return u;
        return parent[u] = findParent(parent[u]);
    }
    void unionn(int u, int v)
    {
        int nu = findParent(u);
        int nv = findParent(v);
        if (nu != nv)
        {
            if (rank[nu] < rank[nv])
                parent[nu] = nv;
            else if (rank[nu] > rank[nv])
                parent[nv] = nu;
            else
            {
                parent[nv] = nu;
                rank[nu]++;
            }
        }
    }
};

class Solution
{
public:
    bool equationsPossible(vector<string> &equations)
    {
        DSU dsu(26);
        for (string x : equations)
        {
            if (x[1] == '=')
                dsu.unionn(x[0] - 'a', x[3] - 'a');
            // else if (x[1] == '!')
            // {
            //     if (dsu.findParent(x[0] - 'a') == dsu.findParent(x[3] - 'a'))
            //         return false;
            // }
        }
        for(string x : equations)
        {
            if(x[1]=='!')
            {
                if (dsu.findParent(x[0] - 'a') == dsu.findParent(x[3] - 'a'))
                    return false;
            }
        }
        return true;
    }
};