class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 0);
        int pIndex = 0, nIndex = 1;
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] > 0)
            {
                ans[pIndex] = nums[i];
                pIndex += 2;
            }
            else if (nums[i] < 0)
            {
                ans[nIndex] = nums[i];
                nIndex += 2;
            }
        }
        return ans;
    }
};
