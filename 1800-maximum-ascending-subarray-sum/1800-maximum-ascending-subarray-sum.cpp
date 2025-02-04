class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int temp=nums[0], ans=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
                temp+=nums[i];
            else {
                ans=max(ans, temp);
                temp = nums[i];
            }
        }
        ans=max(ans, temp);
        return ans;
    }
};