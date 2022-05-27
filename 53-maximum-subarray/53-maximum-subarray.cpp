class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        int cm=nums[0];
        int msf = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            cm = max(nums[i], nums[i]+cm);
            msf = max(cm, msf);
        }
        return msf;
    }
};