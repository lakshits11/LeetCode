class Solution {
public:
    
    int minCost(int n, vector<int>& cuts)
    {
        ios_base::sync_with_stdio(false);
        int c = cuts.size(), cost = 0, mini = INT_MAX;;
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c+2, vector<int>(c+2,0));
        
        for(int i=c;i>0;i--)
        {
            for(int j=i;j<=c; j++)
            {
                mini = INT_MAX;
                for(int k=i;k<=j;++k)
                {
                    cost = cuts[j+1]-cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }
        
        return dp[1][c];
    }
};