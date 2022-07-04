class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> mp(1001, 0);
        int n = nums.size();
        for(int i=0;i<nums.size();i++)
        {
            for(int j =0;j<nums[i].size();j++)
            {
                mp[nums[i][j]]++;
            }
        }
        vector<int> ans;
        for(int i=0;i<=1000;i++)
        {
            if(mp[i]==n)
                ans.push_back(i);
        }
        return ans;
    }
};