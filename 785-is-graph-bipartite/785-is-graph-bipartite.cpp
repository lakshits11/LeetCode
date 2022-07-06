class Solution {
private:
	bool dfs(int node, vector<vector<int>> &adj, vector<int> &color)
	{
		if(color[node]==-1)
			color[node]=1;
		for(int x : adj[node])
		{
			if(color[x]==-1)
			{
				color[x] = !color[node];
				if(!dfs(x, adj, color))
					return false;
			}
			else if(color[x]==color[node])
				return false;
		}
		return true;
	}
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n= adj.size();
        vector<int> color(n, -1);
        for(int i=0;i<n;i++)
        {
        	if(color[i]==-1)
        		if(!dfs(i, adj, color))
        			return false;
        }
        return true;
    }
};
