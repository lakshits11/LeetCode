static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2) return nums.size();
        int inc = 1, dec = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i]>nums[i-1])
                inc = dec+1;
            else if(nums[i]<nums[i-1])
                dec = inc+1;
        }
        return max(inc, dec);
    }
};