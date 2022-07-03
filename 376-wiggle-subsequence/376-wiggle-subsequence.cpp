class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2)   return 1;
        int inc = 1, dec = 1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]<nums[i])
                inc = dec+1;
            else if(nums[i-1]>nums[i])
                dec = inc+1;
        }
        return max(inc, dec);
    }
};