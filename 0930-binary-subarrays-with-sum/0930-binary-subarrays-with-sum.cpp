// same as number of subarrays with exactly k ones.

static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class Solution {
public:
    int f(vector<int> &nums, int k) 
    {
        if(k<0) return 0;
        int l=0, ans=0;
        for(int r=0;r<nums.size();r++)
        {
            k-= nums[r];
            while(k<0)
                k += nums[l++];
            ans += (r - l + 1);
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int k) {
        return f(nums, k)-f(nums,k-1);
    }
};