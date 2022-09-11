class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = nums.size();
        int l = 0, r = 0, len = 0;
        bool zu = false;
        int lz=-1;
        for(r=0;r<n;r++)
        {
            if(nums[r]==0 && !zu)
            {
                zu = true;
                lz=r;
            }
            else if(nums[r]==0 && zu)
            {
                l = lz+1;
                lz = r;
            }
            len = max(len, r-l);
        }
        return len;
    }
};