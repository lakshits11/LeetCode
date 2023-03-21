class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums){
        long long count = 0;
        long long nz = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                count++;
            }
            else if(nums[i]!=0){
                nz += (count*(count+1))/2;
                count=0;
            }
        }
        if(nums[nums.size()-1]==0)
        {
            nz += (count*(count+1)/2);
        }
        return nz;
        
    }
};