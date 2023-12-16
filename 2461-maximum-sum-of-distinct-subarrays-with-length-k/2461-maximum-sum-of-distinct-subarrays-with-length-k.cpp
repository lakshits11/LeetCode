// #define ll long long

static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

long long pos[100001];
class Solution 
{
public:
    long long maximumSubarraySum(vector<int>& nums, int k) 
    {
        long long res = 0, cur = 0, dup = -1;
        // vector<long long> pos(100001,-1); // to store last seen position of an element
        memset(pos, -1, sizeof(pos));
        for (int i = 0; i < nums.size(); ++i)
        {
            cur += nums[i];
            if (i >= k) cur -= nums[i-k]; // after this code, our window size = k condition satisfies
            
            // now we are only left with no duplicate condition
            
            // updating the last seen position of current element
            dup = max(dup, pos[nums[i]]);
            
            // if that position falls out of window, hence we are good to go
            if (i - dup >= k) res = max(res, cur);
            
            // updating current position as last seen position of our current element
            pos[nums[i]] = i;
        }
        
        return res;
    }
};