class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total%2!=0)
            return false;
        int target = total/2;
        
        bool dp[2][target+1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = dp[1][0] = true;
        
        if(nums[0]<=target)
            dp[0][nums[0]] = true;
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=target;j++)
            {
                if(j<nums[i])
                    dp[(i%2)][j] = dp[!(i%2)][j];
                else
                    dp[(i%2)][j] = dp[!(i%2)][j] | dp[!(i%2)][j-nums[i]];
            }
        }
        
        return dp[0][target];
    }
};