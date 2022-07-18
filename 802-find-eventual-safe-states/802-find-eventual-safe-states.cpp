class Solution
{
private:
    unordered_map<int,bool> safe;
    bool dfs(int i, vector<vector<int>> &graph)
    {
        if(safe.find(i) != safe.end())
            return safe[i];
        safe[i] = false;
        for(int x : graph[i])
        {
            if(!dfs(x, graph))
                return false;
        }
        return safe[i]=true;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        vector<int> ans;

        for (int i = 0; i < graph.size(); i++)
        {
            if (dfs(i, graph))
                ans.push_back(i);
        }
        return ans;
    }
};