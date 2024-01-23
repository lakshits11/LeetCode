class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int n = accumulate(nums.begin(), nums.end(), 0);
        int temp=0;
        vector<int> ans;
        for(int i=0;i<nums.size();++i)
        {
            ans.push_back(nums[i]);
            temp+=nums[i];
            n -= nums[i];
            if(temp > n) return ans;
        }
        return ans;
    }
};