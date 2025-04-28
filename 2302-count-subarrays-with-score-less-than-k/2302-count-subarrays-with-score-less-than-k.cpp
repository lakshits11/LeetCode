class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long s = 0, i=0,j=0, ans=0;
        for(j=0;j<nums.size();j++)
        {
            s += nums[j];
            while(s*(j-i+1) >= k && i<=j) {
                s -= nums[i++];
            }
            ans += j-i+1;
        }
        return ans;
    }
};