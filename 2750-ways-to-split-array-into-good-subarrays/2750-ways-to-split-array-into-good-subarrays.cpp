/*
Let us study the first example given in the problem:
Input: nums = [0,1,0,0,1]
Output: 3
Explanation: There are 3 ways to split nums into good subarrays:

    [0,1] [0,0,1]
    [0,1,0] [0,1]
    [0,1,0,0] [1]

    Traverse the input array, before encountering first 1, there is NO good subarray at all. Therefore, we initialize the cnt as 0;
    After finding the first 1, we at least can have 1 good subarray and hence we change cnt from 0 to 1;
    Then the sliding window starts: the previous 1 as lower bound, lo, exclusively, next 1 as upper bound, hi, inclusively (we can refer to the above example for more details.); for each sliding window, we multiply its width, hi - lo, to cnt;
    Repeat step 3 till the end of the input, and the result modulo 1_000_000_007 is the solution.

*/

class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        long ans = 0;
        int mod = 1e9+7;
        for(int l=-1,r=0; r<nums.size(); ++r)
        {
            if(nums[r]==1)
            {
                if(ans==0) ans=1;
                else {
                    ans = ans*(r-l);
                    ans %= mod;
                }
                l=r;
            }
        }
        return ans;
    }
};