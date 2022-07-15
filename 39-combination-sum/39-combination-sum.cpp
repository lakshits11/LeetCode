class Solution {
public:
    void f(int i, vector<int> &nums, int sum, vector<vector<int>> &ans, vector<int> temp)
    {
        if(i==nums.size())
        {
            if(sum==0) {
                ans.push_back(temp);
            }
            return;
        }
        f(i+1, nums, sum, ans, temp);
        if(sum >= nums[i]) {
            temp.push_back(nums[i]);
            f(i, nums, sum-nums[i], ans, temp);
            // temp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        f(0, nums, target, ans, temp);
        return ans;
    }
};