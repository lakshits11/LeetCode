class Solution {
private:
    int f(vector<int> &nums, int k)
    {
        int r = 0, l = 0, ans = 0;
        unordered_map<int, int> m;
        while(r < nums.size())
        {
            m[nums[r]]++;
            while(m.size()>k)
            {
                m[nums[l]]--;
                if(m[nums[l]] == 0)
                    m.erase(nums[l]);
                l++;
            }
            ans += (r-l+1);
            r++;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums, k) - f(nums, k-1);
    }
};