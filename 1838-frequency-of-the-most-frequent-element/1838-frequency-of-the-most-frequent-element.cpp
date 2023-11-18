class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
    int res = 1;
    sort(begin(nums), end(nums));
    for (int i = nums.size() - 1, j = i; i > 0; --i) {
        for (; j >= 0 && k >= nums[i] - nums[j]; --j)
            k -= nums[i] - nums[j];
        res = max(res, i - j);
        k += (nums[i] - nums[i - 1]) * (i - j - 1);
    }
    return res;
}
};