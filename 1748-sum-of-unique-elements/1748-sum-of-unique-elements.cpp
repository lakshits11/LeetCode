class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> arr(101, 0);
        for(int n : nums)
        {
            arr[n]++;
        }
        int ans = 0;
        for(int n : nums)
        {
            if(arr[n]==1)
                ans +=n;
        }
        return ans;
    }
};