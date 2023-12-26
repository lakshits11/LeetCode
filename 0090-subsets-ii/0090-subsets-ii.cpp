class Solution {
public:
    set<vector<int>> s;
    vector<vector<int>> ans;
    
    void dfs(int i, vector<int> &temp, vector<int> &nums)
    {
        s.insert(temp);
        for(int j=i;j<nums.size();j++)
        {
            temp.push_back(nums[j]);
            dfs(j+1, temp, nums);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(), nums.end());
        dfs(0, temp, nums);
        for(const auto &it : s)
            ans.push_back(it);
        return ans;
    }
};