class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long ts = 0;
        int n = nums.size();
        long cs = 0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ts+=nums[i];
        }
        for(int i=0;i<n-1;i++)
        {
            cs+=nums[i];
            ts -= nums[i];
            if(cs>=ts) ans++;
        }
        return ans;
    }
};