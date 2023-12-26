static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class Solution {
public:
    vector<vector<int>> ans;
    
    void dfs(int i, vector<int> &temp, vector<int> &nums)
    {
        ans.push_back(temp);
        for(int j = i; j < nums.size(); j++)
        {
            temp.push_back(nums[j]);
            dfs(j+1, temp, nums);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums){
        vector<int> temp;
        dfs(0, temp, nums);
        return ans;
    }
};