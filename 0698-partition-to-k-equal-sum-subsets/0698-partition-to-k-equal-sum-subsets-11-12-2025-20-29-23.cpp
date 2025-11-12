class Solution {
public:
    // ind, how many partitions are left to build, current sum of subset, target, used array to keep track of elements used till now
    bool backtrack(int i, int k, int subsetSum, int &target, vector<bool> &used, vector<int> &nums)
    {
        
        if(k == 0)
            return true;
        
        // It means now we need to make k-1 partitions more, so as soon as subset sum equals targetValue, backtrack and again start from 0th index to make k-1 partitions more
        if(subsetSum == target)
            return backtrack(0, k-1, 0, target, used, nums);
        
        for(int j = i; j < nums.size(); j++)
        {
            if(used[j] || subsetSum+nums[j] > target)
                continue;
            used[j] = true;
            if (backtrack(j+1, k, subsetSum+nums[j], target, used, nums))
                return true;
            used[j] = false;
        }
        return false;
        
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        int target = 0, maxi = INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            target += nums[i];
            maxi = max(maxi, nums[i]);
        }
        if(nums.size() < k || target % k != 0)
            return false;
        target /= k;
        if(maxi > target)
            return false;
        vector<bool> used(nums.size(), false);
        return backtrack(0, k, 0, target, used, nums);
    }
};