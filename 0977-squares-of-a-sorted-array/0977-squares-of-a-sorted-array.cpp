
static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

bool comp(int a, int b)
{
    return abs(a)<abs(b);
}

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);
        for(int i=0;i<nums.size();++i)
        {
            nums[i] = (nums[i]*nums[i]);
        }
        return nums;
    }
};