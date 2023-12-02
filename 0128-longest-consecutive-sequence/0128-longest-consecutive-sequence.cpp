class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);
        int n = nums.size();
        if(n==0) return 0;
        sort(nums.begin(), nums.end());
        int ccs = 1;
        int lcs = 0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]!=nums[i-1])
            {
                if(nums[i]==nums[i-1]+1) ccs++;
                else {
                    lcs = max(lcs, ccs);
                    ccs = 1;
                }
            }
        }
        return max(lcs, ccs);
    }
};