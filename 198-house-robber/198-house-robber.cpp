class Solution {
public:
    int rob(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        int n = nums.size(), prev2, prev1, curr;
        if(n==1)    return nums[0];
        if(n==2)    return max(nums[0], nums[1]);
        prev2 = nums[0];
        prev1 = max(nums[0], nums[1]);
        for(int i=2; i<n; i++)
        {
            curr = max(prev2+nums[i], prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};