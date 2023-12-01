class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int cz = 0;
        long long prod = 1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                cz++;
            }
            else prod = prod*nums[i];
        }
        cout << prod << "\n";
        for(int i = 0; i < nums.size(); i++)
        {
            if(cz>1) nums[i]=0;
            else if(cz==1 && nums[i]!=0) nums[i]=0;
            else if(cz==1 && nums[i]==0) nums[i]=prod;
            else nums[i]=prod/nums[i];
        }
        return nums;
    }
};