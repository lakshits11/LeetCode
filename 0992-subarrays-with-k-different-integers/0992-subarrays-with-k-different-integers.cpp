class Solution {
private:
    int f(vector<int> &nums, int k)
    {
        /*
        atMost(k) is calculating the number of sub-arrays with no more than k different integers. i.e. atmost k integers
so whenever r is moved to the right, the
number of sub-arrays with no more than k different numbers increases by (r - l +1)
        */
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