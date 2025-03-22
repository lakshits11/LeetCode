static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class Solution {
public:
    vector<int> parent, ec, nc;
    
    int find(int i)
    {
        if(parent[i] == -1) return i;
        return find(parent[i]);
    }

    void unionn(int a, int b)
    {
        a = find(a), b = find(b);
        ec[a]++;
        if(a != b) {
            parent[b] = a;
            ec[a] += ec[b];
            nc[a] += nc[b];
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        parent.resize(n, -1);
        ec.resize(n, 0);
        nc.resize(n, 1);

        for(vector<int> &e : edges) unionn(e[0], e[1]);

        for(int i = 0; i < n; i++)
        {
            if(nc[i] && parent[i]==-1 && (nc[i]*(nc[i]-1)/2)==ec[i])
                ans++;
        }

        return ans;
    }
};