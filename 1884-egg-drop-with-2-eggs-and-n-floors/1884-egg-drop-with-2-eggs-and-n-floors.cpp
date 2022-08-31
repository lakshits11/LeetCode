class Solution {
public:
    int twoEggDrop(int n) {
        int f = n, e = 2;
        vector<vector<int>> dp(f+1, vector<int>(e+1, 0));
        int m = 0; // moves
        
        // dp[M][E] means that, given E eggs and M moves, what is the maximum number of floor that we can check.
        while(dp[m][e] < f)
        {
            m++;
            for(int k = 1; k <= e; k++)
                dp[m][k] = dp[m-1][k-1] + dp[m-1][k] + 1;
        }
        return m;
    }
};