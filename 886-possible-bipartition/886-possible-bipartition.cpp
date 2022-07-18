class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dslk) {
        
        vector<int> adj[n+1];
        for(vector<int> x : dslk)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> color(n+1, -1);
        for(int i=1;i<=n;i++)
        {
            if(color[i]!=-1)
                continue;
            queue<int> q;
            q.push(i);
            color[i] = 1;
            while(!q.empty())
            {
                int t = q.front();
                q.pop();
                for(int x : adj[t])
                {
                    if(color[x] == -1){
                        color[x] = !color[t];
                        q.push(x);
                    }
                    else if(color[x] == color[t])
                        return false;
                }
            }
        }
        return true;
    }
};