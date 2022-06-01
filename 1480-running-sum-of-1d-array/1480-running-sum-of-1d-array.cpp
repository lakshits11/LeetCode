class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        for(int i=1;i<nums.size();i++)
        {
            nums[i] = nums[i-1]+nums[i];
        }
        return nums;
    }
};