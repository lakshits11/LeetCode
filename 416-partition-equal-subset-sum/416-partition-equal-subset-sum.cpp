class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0), target = sum >> 1;
        if (sum & 1) return false;
        bitset<10001> dp(1);

        for(auto num : nums) 
            dp = dp | dp<<num;
        return dp[target];
    }
};