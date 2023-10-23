class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size(), ans=0;
        sort(nums.begin(), nums.end());
        int lo=0, hi=n-1;
        while(lo<hi)
        {
            if(nums[lo]+nums[hi] < target)
            {
                ans += (hi-lo);
                lo++;
            }
            else hi--;
        }
        return ans;
    }
};