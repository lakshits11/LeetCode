class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        nth_element(nums.begin(), nums.begin()+k-1, nums.end(), greater<int>());
        return nums[k-1];
    }
};