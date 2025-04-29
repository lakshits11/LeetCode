class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long maxi = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            maxi = max((long long)nums[i], maxi);
        }
        long long n = nums.size();
        long long l = 0, kc = 0, ans = 0;
        for (int r = 0; r < nums.size(); r++)
        {
            kc += (nums[r] == maxi);
            while (kc >= k) 
            {
                ans += (n - r);
                if (nums[l++] == maxi)
                    kc--;
            }
        }
        return ans;
    }
};