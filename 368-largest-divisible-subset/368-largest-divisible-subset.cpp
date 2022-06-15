class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        ios_base::sync_with_stdio(false);
        sort(nums.begin(), nums.end());
        int n = nums.size(), res = 1, lastIndex;
        vector<int> dp(n, 1), hash(n);

        for (int i = 1; i < n; ++i)
        {
            hash[i] = i;
            for (int j = 0; j < i; ++j)
            {
                if ((nums[i] % nums[j] == 0) && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if(dp[i]>res){
                res = dp[i];
                lastIndex = i;
            }
        }
        vector<int> ans(res);
        ans[0]=nums[lastIndex];
        int ind = 1;
        while (hash[lastIndex] != lastIndex)
        {
            lastIndex = hash[lastIndex];
            ans[ind++] = nums[lastIndex];
        }
        return ans;
    }
};