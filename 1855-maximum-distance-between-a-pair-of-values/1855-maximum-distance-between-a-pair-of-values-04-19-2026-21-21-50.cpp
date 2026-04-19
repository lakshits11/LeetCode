class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        reverse(nums2.begin(), nums2.end());
        int n = nums2.size();
        int ans = 0;
        for(int i = 0; i < nums1.size() && i <= nums2.size(); i++)
        {
            auto it = lower_bound(nums2.begin(), nums2.end()-i, nums1[i]);
            int index = std::distance(nums2.begin(), it);
            ans = max(ans, n - index - 1 - i);
        }
        return ans;
    }
};