class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() ;
        for(int i = 0; i <n;i++)
        {
            int x = abs(nums[i])-1;
            if(nums[x]<0)
                return x+1;
            else nums[x] *= (-1);
        }
        return -1;
    }
};