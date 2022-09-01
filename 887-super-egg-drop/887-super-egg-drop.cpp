class Solution {
public:
    int superEggDrop(int e, int f)
    {
        vector<vector<int>> dp(f+1, vector<int>(e+1, 0));
        int m = 0;
        
        while(dp[m][e] < f)
        {
            m++;
            for(int k = 1; k <= e; k++)
            {
                dp[m][k] = dp[m-1][k-1] + dp[m-1][k] + 1;
            }
        }
        return m;
        
    }
};