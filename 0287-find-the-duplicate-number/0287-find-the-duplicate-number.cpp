class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);
        for(int i=0;i<nums.size();++i)
        {
            if(nums[abs(nums[i])] < 0)
                return abs(nums[i]);
            nums[abs(nums[i])] = -nums[abs(nums[i])];
        }
        return 0;
    }
};

