class Solution {
    public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            int diff = k - nums[i];
            if(m.count(diff))
            {
                ans++;
                if(m[diff]==1) m.erase(diff);
                else m[diff]--;
            }
            else m[nums[i]]++;
        }
        return ans;
    }
};