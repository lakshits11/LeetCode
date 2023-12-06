class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);
        int cm = nums[0];
        int ms = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            cm = max(nums[i], nums[i]+cm);
            ms = max(ms, cm);
        }
        return ms;
    }
};