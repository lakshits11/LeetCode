class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        long ans = 0;
        int mod = 1e9+7;
        for(int l=-1,r=0; r<nums.size(); ++r)
        {
            if(nums[r]==1)
            {
                if(ans==0) ans=1;
                else {
                    ans = ans*(r-l);
                    ans %= mod;
                }
                l=r;
            }
        }
        return ans;
    }
};