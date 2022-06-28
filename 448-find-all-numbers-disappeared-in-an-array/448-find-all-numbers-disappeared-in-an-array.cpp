class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);
        for(int i=0;i<nums.size();i++)
        {
            int ind = abs(nums[i])-1;
            if(nums[ind]>0)
                nums[ind] = -nums[ind];
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
                ans.push_back(i+1);
        }
        return ans;
    }
};