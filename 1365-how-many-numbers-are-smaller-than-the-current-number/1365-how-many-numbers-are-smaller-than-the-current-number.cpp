class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        int bucket[102] = {0};
        for(int x = 0; x < n; x++)
            bucket[nums[x]+1]++;
        for(int i=1;i<102;i++)
            bucket[i] += bucket[i-1];
        for(int i=0;i<n;i++)
        {
            nums[i] = bucket[nums[i]];
        }
        return nums;
    }
};