class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0, len = 0;
        bool zu = false;int lz=-1;
        while(r < n)
        {
            if(nums[r]==0 && !zu)
            {
                zu = true;
                lz=r;
            }
            else if(nums[r]==0 && zu)
            {
                l = lz+1;
                lz=r;
            }
            len = max(len, r-l);
            r++;
        }
        return len;
    }
};