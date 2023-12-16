static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int num=0, j=0, ans=0;
        for(int i=0;i<nums.size();i++)
        {
            while((num & nums[i]) != 0)
            {
                // keep removing numbers from back of window until this problem is resolved
                num ^= nums[j++];
            }
            
            // no problem here
            num |= nums[i]; // setting bits inside nums with out current element
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};