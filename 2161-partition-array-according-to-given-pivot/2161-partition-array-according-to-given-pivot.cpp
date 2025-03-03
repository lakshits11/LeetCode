class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) 
    {
        vector<int> temp(nums.size());
        int a=0,b=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<pivot) a++;
            else if(nums[i]==pivot) b++;
        }

        int ss=0,ps=a,gs=a+b;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<pivot) temp[ss++] = nums[i];
            else if(nums[i] == pivot) temp[ps++] = nums[i];
            else temp[gs++] = nums[i];
        }
        return temp;


    }
};