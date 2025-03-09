class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int temp = 0, ans = 0;
        for(int i=0;i<nums.size()-1;i++)
        {
            temp += nums[i];
            if((total-2*temp)%2==0) 
                ans++;
        }
        return ans;
    }
};