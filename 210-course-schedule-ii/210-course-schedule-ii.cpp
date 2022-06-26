class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(int i=0;i<pre.size();i++)
        {
            adj[pre[i][1]].push_back(pre[i][0]);
            indegree[pre[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
            if(indegree[i]==0)
                q.push(i);
        
        vector<int> topo;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            if(topo.size()==n)
                break;
            for(int x : adj[node])
                if(--indegree[x]==0)
                    q.push(x);
        }
        // unordered_map<int, int> u;
        // for(int i=0;i<topo.size();i++)
        //     u[i] = topo[i];
        // for(int i=0;i<n;i++)
        // {
        //     for(int x: adj[i])
        //         if(u[i]>u[x])
        //             return {};
        // }
        if(topo.size()!=n)
            return {};
        return topo;
    }
};