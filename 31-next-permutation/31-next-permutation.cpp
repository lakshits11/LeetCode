class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        int n = nums.size(), k, l;
        
        // finding a break point
        for(k = n-2; k >= 0; k--)
        {
            if(nums[k]<nums[k+1])
                break;
        }

        // if we didnt found any break point, it means we are at last permutation
        // and we have ti return the first (starting) permutation, and that will be sorted value of array, (in present, we have reverse sorted array)
        if(k<0)
            reverse(nums.begin(), nums.end());

        else
        {
            // else again start traversing from back and find the
            // first index whose value is greater than nums[k]
            for(l = n-1; l > k; l--)
            {
                if(nums[l] > nums[k])
                    break;
            }
            swap(nums[k], nums[l]);
            reverse(nums.begin()+k+1, nums.end());
        }        
        
    }
};
