class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i = 0, j = 0, ans = -1;
        while(i < nums.size())
        {
            if(nums[i] != 1)
            {
                ans = max(ans, i-j);
                j = i+1;
            }
            i++;
        }
        ans = max(ans, i-j);
        return ans;
    }
};