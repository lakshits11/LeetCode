#define mod 1000000007

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& qr) {
        for(vector<int> &q : qr)
        {
            for(int i=q[0]; i <= q[1]; i += q[2])
            {
                long long z = (long long)nums[i] * q[3];
                nums[i] = (z) % mod;
            }
        }

        int ans = nums[0];
        for(int i=1;i<nums.size();i++) ans = (ans ^ nums[i]);
        return ans;
    }
};