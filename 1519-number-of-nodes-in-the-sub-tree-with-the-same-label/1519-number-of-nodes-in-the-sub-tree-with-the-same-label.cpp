class Solution {
private:
    void dfs(int node, int par, vector<int> adj[], vector<vector<int>> &dp, vector<int> &ans, string &labels)
    {
        dp[node][labels[node]-'a']++;
        for(int &child : adj[node])
        {
            if(child != par)
            {
                dfs(child, node, adj, dp, ans, labels);
                for(int i=0; i<26; i++)
                {
                    dp[node][i] += dp[child][i];
                }
            }
        }
        ans[node] = dp[node][labels[node]-'a'];
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels)
    {
        vector<int> adj[n];
        for(int i=0; i<edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<vector<int>> dp(n, vector<int>(26,0));
        vector<int> ans(n);
        dfs(0, -1, adj, dp, ans, labels);
        return ans;
    }
};