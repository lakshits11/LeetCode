class Solution
{
public:
    int shortestPathLength(vector<vector<int>> &g)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = g.size();
        int all = (1 << n) - 1;
        // <current node, <current distance till now, current mask>>
        queue<pair<int, pair<int, int>>> q;
        // NOTE: current mask will be 1<<i

        // <node, mask>
        // visited basically is storing {node, combination of nodes visited to reach that node}
        set<pair<int, int>> vis;

        // we will be adding all the nodes in the queue
        for (int i = 0; i < n; ++i)
        {
            int mask = (1 << i);
            q.push({i, {0, mask}});
            // node i and its mask are being inserted into vis set
            vis.insert({i, mask});
        }

        while (!q.empty())
        {
            pair<int, pair<int, int>> node = q.front();
            q.pop();
            int nodeVal = node.first, currDis = node.second.first, currMask = node.second.second;
            for (auto nbr : g[nodeVal])
            {
                int newMask = currMask | (1 << nbr);
                if (newMask == all)
                    return currDis + 1;
                else if (vis.count({nbr, newMask}))
                    continue;
                else
                {
                    q.push({nbr, {currDis + 1, newMask}});
                    vis.insert({nbr, newMask});
                }
            }
        }

        return 0;
    }
};