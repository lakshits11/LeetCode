static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        if (nums.size() < 3) return 0;
        int prevDiff = nums[1] - nums[0];
        int ans = 0, len = 0;
        for (int r = 1; r < nums.size() - 1; r++)
        {
            int currDiff = nums[r + 1] - nums[r];
            if (currDiff == prevDiff)
            {
                len++;
            }
            else
            {
                prevDiff = currDiff;
                len = 0;
            }
            ans += len;
        }
        return ans;
    }
};