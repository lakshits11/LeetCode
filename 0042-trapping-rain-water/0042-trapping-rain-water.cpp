// https://leetcode.com/problems/trapping-rain-water/solutions/17357/sharing-my-simple-c-code-o-n-time-o-1-space

// basically we want to calculate amount of water  held above each container
// this will depend on first greater height container on its left side and on
// right side

static const auto speedup = []() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int trap(vector<int>& ht) {
        int n = ht.size();
        // ml = maximumLeft, mr = maximumRight
        int l = 0, r = n - 1, ml = 0, mr = 0;
        int ans = 0;
        while (l <= r) 
        {
            if (ht[l] <= ht[r]) 
            {
                if (ht[l] > ml)
                    ml = ht[l];
                else
                    ans += ml - ht[l];
                l++;
            } 
            else 
            {
                if (ht[r] > mr)
                    mr = ht[r];
                else
                    ans += mr - ht[r];
                r--;
            }
        }
        return ans;
    }
};