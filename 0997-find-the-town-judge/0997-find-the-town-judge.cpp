class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int indegree[n+1];
        int outdegree[n+1];
        
        for (int i = 0; i < n + 1; i++)
        {
            indegree[i] = 0;
            outdegree[i] = 0;
        }
        
        for(int i=0;i<trust.size();i++)
        {
            outdegree[trust[i][0]]++;
            indegree[trust[i][1]]++;
        }
        
        for(int i=1;i<=n;i++)
        {
            if(outdegree[i]==0 && indegree[i]==n-1)
                return i;
        }
        
        return -1;
    }
};