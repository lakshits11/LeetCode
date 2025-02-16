class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> u;
        long long gp=0, n=nums.size();
        for(int i=0; i<nums.size();i++)
        {
            int k = nums[i]-i;
            gp += u[k];
            u[k]++;
        }

        return (n-1)*n/2 - gp;
    }
};