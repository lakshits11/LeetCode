class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        int r = 0, l = 0, s = 0, n = nums.size(), ans = INT_MAX;
        while(r < n)
        {
            s += nums[r++];
            while(s >= target)
            {
                ans = min(ans, r-l);
                s -= nums[l++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};