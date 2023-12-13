class Solution {
public:
    int f(vector<int> &nums, int k)
    {
        if(k<0) return 0;
        int l=0, ans=0;
        for(int r=0;r<nums.size();r++)
        {
            k -= (nums[r]%2);
            while(k<0)
            {
                k += (nums[l]%2);
                l++;
            }
            ans += (r-l+1);
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums, k)-f(nums, k-1);
    }
};