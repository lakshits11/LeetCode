class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> adj(n);
        vector<int> time(n, -1);

        for(vector<int> &x  : edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        queue<int> q;
        q.push(0);
        time[0] = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(int nbr : adj[node])
            {
                if(time[nbr] == -1)
                {
                    time[nbr] = time[node] + 1;
                    q.push(nbr);
                }
            }
        }

        int ans = 0;
        for(int i=1;i<n;i++)
        {
            int extraMsgs = (time[i]*2 - 1)/patience[i];

            int lastOut = extraMsgs * patience[i];
            int totalTime = lastOut + time[i]*2;

            ans = max(ans, totalTime);
        }
        return ans+1;
    }
};