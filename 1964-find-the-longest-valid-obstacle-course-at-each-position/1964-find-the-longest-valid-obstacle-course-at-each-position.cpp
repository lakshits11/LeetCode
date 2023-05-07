class MaxBIT {
    vector<int> bit;
public:
    MaxBIT(int size) {
        bit.resize(size + 1);
    }
    int get(int idx) {
        int ans = 0;
        for (; idx > 0; idx -= idx & -idx)
            ans = max(ans, bit[idx]);
        return ans;
    }
    void update(int idx, int val) {
        for (; idx < bit.size(); idx += idx & -idx)
            bit[idx] = max(bit[idx], val);
    }
};
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums) {
        int nUnique = compress(nums);
        MaxBIT bit(nUnique);
        for (int i = 0; i < nums.size(); ++i) {
            int subLongest = bit.get(nums[i]) + 1;
            bit.update(nums[i], subLongest);
            nums[i] = subLongest;
        }
        return nums;
    }
    int compress(vector<int>& arr) { // For example: arr = [1, 9999, 20, 10, 20]
        vector<int> uniqueSorted(arr);
        sort(uniqueSorted.begin(), uniqueSorted.end());
        uniqueSorted.erase(unique(uniqueSorted.begin(), uniqueSorted.end()), uniqueSorted.end()); // Remove duplicated values
        for (int& x : arr) x = lower_bound(uniqueSorted.begin(), uniqueSorted.end(), x) - uniqueSorted.begin() + 1;
        return uniqueSorted.size(); // Result: arr = [1, 4, 3, 2, 3]
    }
};