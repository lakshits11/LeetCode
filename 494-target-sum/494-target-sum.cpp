class Solution
{
public:
    int total = 0, n;
    int f(vector<int> &nums, int i, int sum, int target, vector<vector<int>> &dp)
    {
        if (i == n && sum == target)
            return 1;
        if (i == n)
            return 0;
        
        if (dp[i][sum+total] != -1)
            return dp[i][sum+total];
        
        return dp[i][sum+total] = f(nums, i + 1, sum + nums[i], target, dp) + f(nums, i + 1, sum - nums[i], target, dp);
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        n = nums.size();
        for (int i = 0; i < n; i++){
            total += nums[i];
        }
        vector<vector<int>> dp(n, vector<int>((2 * total) + 1, -1));
        return f(nums, 0, 0, target, dp);
    }
};