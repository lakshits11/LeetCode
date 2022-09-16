class Solution {
public:
    
    int solve(vector<int>& nums, vector<int>& multipliers, int l, int i, vector<vector<int>> &dp){
        int n = multipliers.size();
        if(i >= n || l>=n) return 0;
        if(dp[l][i] != INT_MAX) return dp[l][i];
        
        int r = nums.size() - 1 - (i-l);
        int left = solve(nums, multipliers, l+1, i+1, dp) + (nums[l]*multipliers[i]);
        int right = solve(nums, multipliers, l, i+1, dp) + (nums[r]*multipliers[i]);
        return dp[l][i] = max(left, right);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m = multipliers.size();
        vector<vector<int>> dp(m+1, vector<int>(m+1, INT_MAX));
        return solve(nums, multipliers, 0, 0, dp);
    }
};