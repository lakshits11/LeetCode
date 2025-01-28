// explanation: https://leetcode.com/problems/minimum-number-of-operations-to-satisfy-conditions/solutions/5052484/complete-explanation-easy-to-understand-dp
// code: https://leetcode.com/problems/minimum-number-of-operations-to-satisfy-conditions/solutions/5052630/dp-both-top-down-bottom-up-c


static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();
class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> cost(n, vector<int>(11, 0));
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<m;i++)
            {
                cost[j][grid[i][j]]++;
            }
        }

        vector<vector<int>> dp(n, vector<int>(10, 2e9));

        for(int j = 0; j < n; j++)
        {
            for(int val = 0; val < 10; val++)
            {
                for(int prevVal = 0; prevVal < 10; prevVal++)
                {
                    if(val != prevVal)
                    {
                        dp[j][val] = min( 
                                    dp[j][val], 
                                    m - cost[j][val] + (j ? dp[j-1][prevVal] : 0) 
                                );
                    }
                }
            }
        }

        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};