class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int s = n*(n+1)/2;
        for(int i=0;i<n;i++)
        {
            s-=nums[i];
        }
        return s;
    }
};