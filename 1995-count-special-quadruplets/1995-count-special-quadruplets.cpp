class Solution {
public:
    int countQuadruplets(vector<int>& nums)
    {
        int n = nums.size(), ans = 0;
        unordered_map<int, int> u;
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = i - 1; j >= 0; j--)
            {
                for(int k = j -1; k >= 0; k--)
                {
                    ans += u[nums[i]+nums[j]+nums[k]];
                }
            }
            u[nums[i]]++;
        }
        return ans;
    }
};