class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<pair<int, int>> g[n + 1];
        for (auto it : times)
        {
            g[it[0]].push_back(make_pair(it[1], it[2]));
        }
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({k, 0});
        dist[k] = 0;
        while (!pq.empty())
        {
            int node = pq.top().first;
            int dis = pq.top().second;
            pq.pop();
            for (auto it : g[node])
            {
                int newnode = it.first;
                int newdis = it.second;
                if (dist[node] + newdis < dist[newnode])
                {
                    dist[newnode] = dist[node] + newdis;
                    pq.push({newnode, dist[newnode]});
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (dist[i] == INT_MAX)
                return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};