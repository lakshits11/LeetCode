class Solution {
private:
    int f(int l, int r, vector<int> &nums)
    {
        if(l==r) return l;
        int mid = l + (r-l)/2;
        if(nums[mid]<nums[mid+1])
            return f(mid+1, r, nums);
        return f(l, mid, nums);
    }
public:
    int findPeakElement(vector<int>& nums) {
        return f(0, nums.size()-1, nums);
    }
};