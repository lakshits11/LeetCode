class Solution
{
private:
    int findParent(int u, vector<int> &parent)
    {
        if (parent[u] == -1)
            return u;
        return parent[u] = findParent(parent[u], parent);
    }
    void unionn(int u, int v, vector<int> &parent, vector<int> &rank)
    {
        int nu = findParent(u, parent);
        int nv = findParent(v, parent);
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

public:
    int removeStones(vector<vector<int>> &stones)
    {
        //  DSU dsu(20001);
        vector<int> parent(20005, -1);
        vector<int> rank(20005, 1);
        for (vector<int> stone : stones)
            unionn(stone[0], stone[1] + 10001, parent, rank);
        set<int> s;
        for (vector<int> stone : stones)
            s.insert(findParent(stone[0], parent));
        return stones.size() - s.size();
    }
};