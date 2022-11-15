class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int count = 0;
        for(int i = 0; i < size(nums); i++)
        {
            int currLCM = 1;
            for(int j = i; j < nums.size(); j++)
            {
                currLCM = lcm(currLCM, nums[j]);
                if(currLCM == k) count++;
                if(currLCM > k) break;
            }
        }
        return count;
    }
};