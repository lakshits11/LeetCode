// By Lakshit Somani
#include <bits/stdc++.h>
using namespace std;

static const auto speedup = []() -> int
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    vector<vector<int>> ans;
    vector<bool> used;
    void rec(vector<int> &temp, vector<int> &nums)
    {
        if(temp.size() == nums.size())
        {
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); ++i)
        {
            if(used[i]) continue;
            if(i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
            used[i] = true;
            temp.push_back(nums[i]);
            rec(temp, nums);
            used[i] = false;
            temp.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        used.resize(nums.size(), false);
        rec(temp, nums);
        return ans;
    }
};