class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans = 0;
        for(int &n : nums)
        {
            ans ^= n;
        }
        return ans;
    }
};