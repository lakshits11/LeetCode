/*
Any nums[i] is a number between 0 and n - 1. It is smaller than n. If B = K * n, K is a positive integer, then (nums[i] + B) / n = K. You can think of B is our nums[nums[i]]%n here.

If we add a number to nums[i], we don't want it to affect the way we find nums[nums[i]]. Let use C to represent (n * (nums[nums[i]]%n)). Obviously, C % n == 0. So (nums[i] + C) % n = nums[i]. (nums[i] mod n) == ((nums[i] + C) mod n)

We are manipulating nums[i] from index 0 to n - 1, so when we access nums[nums[i]], nums[i] hasn't been touched yet. It means nums[i] is between 0 and n - 1, so nums[nums[i]] works fine.
*/

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=nums[i]+(n*(nums[nums[i]]%n));
        }
        for(int i=0;i<n;i++){
            nums[i]/=n;
        }
        return nums;
    }
};