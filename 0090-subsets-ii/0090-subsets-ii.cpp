class Solution {
public:
    vector<vector<int>> ans;
    
    void dfs(int i, vector<int> &temp, vector<int> &nums)
    {
        ans.push_back(temp);
        for(int j=i;j<nums.size();j++)
        {
            if(j>i && nums[j]==nums[j-1]) continue;
            temp.push_back(nums[j]);
            dfs(j+1, temp, nums);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(), nums.end());
        dfs(0, temp, nums);
        return ans;
    }
};