class Solution {
public:
    class tuple
    {
        public:
        int node, mask,cost;
        tuple(int node, int mask, int cost)
        {
            this->node = node;
            this->mask = mask;
            this->cost = cost;
        }
    };
    
    int shortestPathLength(vector<vector<int>>& graph) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = graph.size();
        queue<tuple> q;
        set<pair<int, int>> vis;
        int all = (1<<n)-1;
        for(int i = 0; i < n; ++i)
        {
            int maskValue = 1<<i; // 2^i
            tuple thisNode(i, maskValue, 1);
            q.push(thisNode);
            vis.insert({i, maskValue});
        }
        
        while(!q.empty())
        {
            tuple curr = q.front();
            q.pop();
            if(curr.mask == all)
                return curr.cost-1;
            
            for(int &adjNode : graph[curr.node])
            {
                int currMask = curr.mask;
                currMask = currMask | (1<<adjNode);
                tuple ThisNode(adjNode, currMask, curr.cost+1);
                if(vis.find({adjNode, currMask}) == vis.end())
                {
                    vis.insert({adjNode, currMask});
                    q.push(ThisNode);
                }
            }
        }
        
        return -1;
    }
};