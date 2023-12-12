class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int m1 = INT_MIN, m2 = -1, count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == m1) count++;
            if (nums[i] > m1)
            {
                m1 = nums[i];
                count = 1;
            }
        }
        if (count > 1) return (m1 - 1) * (m1 - 1);
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != m1 && (m2 == -1 || nums[i] > m2))
            {
                m2 = nums[i];
            }
        }
        return (m1 - 1) * (m2 - 1);
    }
};