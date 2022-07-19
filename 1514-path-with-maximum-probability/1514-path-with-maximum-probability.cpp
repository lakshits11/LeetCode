class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {
        vector<pair<int, double>> adj[n];
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        vector<int> seen(n, 0);

        priority_queue<pair<double, int>> q;
        q.push({(double)1.00, start}); // distance of node from source, node

        vector<double> maxp(n, double(0.00));
        maxp[start] = 1.00;

        while (!q.empty())
        {
            pair<double, int> temp = q.top();
            q.pop();
            double prob = temp.first;
            int node = temp.second;
            if (!seen[node])
            {
                seen[node]++;
                for (auto x : adj[node])
                {
                    if (prob * x.second > maxp[x.first])
                    {
                        maxp[x.first] = temp.first * x.second;
                        q.push({maxp[x.first], x.first});
                    }
                }
            }
        }
        return maxp[end];
    }
};