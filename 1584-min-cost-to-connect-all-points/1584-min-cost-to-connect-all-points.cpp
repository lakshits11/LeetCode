class Solution {
public:
    vector<int> parent;
    vector<int> rankk;
    
    struct node
    {
        int u, v, wt;
        node(int wgt, int i, int j)
        {
            wt=wgt;
            u=i;
            v=j;
        }
    };
    
    int findp(int u)
    {
        if(u==parent[u]) return u;
        return parent[u] = findp(parent[u]);
    }
    
    void uni(int u, int v)
    {
        u = findp(u);
        v = findp(v);
        if(rankk[u]<rankk[v]) swap(u,v);
        parent[v]=u;
        if(rankk[u]==rankk[v]) rankk[u]++;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        // APPROACH THINKING
        // firstly connect each pair of points wiht a weighted edge and
        // then find mst weight amongst them. that will be minimum cost to
        // connect all paths
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = points.size();
        // weight and point coordinates
        vector<node> adj;
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                // connects points[i] to points[j]
                // not vice cersa since we will be using DSU to find MST
                int wt = abs(points[j][0]-points[i][0]) + abs(points[j][1] - points[i][1]);
                adj.push_back(node(wt, i, j));
            }
        }
        
        // now we have a mst built with node distances as weights and node values as 0, 1, 2...n-1
        parent.resize(n);
        rankk.resize(n, 1);
        for(int i=0;i<n;i++)
            parent[i]=i;
        
        int cost = 0;
        sort(adj.begin(), adj.end(), [](const node& a, const node& b) {
            return a.wt < b.wt;
        });
        for(auto it : adj)
        {
            if(findp(it.u) != findp(it.v))
            {
                cost += it.wt;
                uni(it.u, it.v);
            }
        }
        return cost;
        
    }
};