class Solution {
public:
    void f(vector<int> &nums, set <vector<int>> &sres, vector<int> temp, int ind)
    {
        if(ind == nums.size())
        {
            sort(temp.begin(), temp.end());
            sres.insert(temp);
            return;
        }
        // Not taking
        f(nums, sres, temp, ind+1);
        // taking
        temp.push_back(nums[ind]);
        f(nums, sres, temp, ind+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        set <vector<int>> sres;
        f(nums, sres, temp, 0);
        for(vector<int> x : sres)
        {
            ans.push_back(x);
        }
        return ans;
    }
};