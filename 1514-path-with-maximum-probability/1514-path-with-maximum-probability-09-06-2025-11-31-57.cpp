class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& e, vector<double>& s, int start, int end) {
        vector<double> dist(n, 0.0);
        vector<vector<pair<double, int>>> adj(n, vector<pair<double, int>>());
        for(int x=0;x<e.size();x++)
        {
            adj[e[x][0]].push_back({s[x], e[x][1]});
            adj[e[x][1]].push_back({s[x], e[x][0]});
        }
        dist[start] = 1.0;
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start});

        while(!pq.empty())
        {
            double current_prob = pq.top().first;
            int current_node = pq.top().second;
            pq.pop();

            // Skip if already have found a better prob to reach here
            if(current_prob < dist[current_node]) continue;
            
            // Early termination if we reached the end
            if(current_node == end) return current_prob;
            
            for(auto &x : adj[current_node])
            {
                double nbr_prob = x.first;
                int nbr_node = x.second;
                if(dist[nbr_node] < current_prob*nbr_prob)
                {
                    dist[nbr_node] = current_prob*nbr_prob;
                    pq.push({dist[nbr_node], nbr_node});
                }
            }
        }
        return dist[end];
    }
};