class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_map<int, int> u;
        for(int i=0;i<nums.size()-1;i++)
        {
            u[nums[i]+nums[i+1]]++;
            if(u[nums[i]+nums[i+1]]>1) return true;
        }
        return false;
    }
};