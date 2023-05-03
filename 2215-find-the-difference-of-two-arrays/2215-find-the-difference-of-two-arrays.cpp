class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> sa(begin(nums1), end(nums1)), sb(begin(nums2), end(nums2));
        vector<vector<int>> ans(2);
        for (int n : sa) {
            if (sb.count(n) == 0) ans[0].push_back(n);
        }
        for (int n : sb) {
            if (sa.count(n) == 0) ans[1].push_back(n);
        }
        return ans;
    }
};