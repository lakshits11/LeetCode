class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        
        int n(size(nums));
        for (; n>1; n-=n/2) {
            for (int i=0; i<n/2; i++) {
                nums[i] = ((i % 2 == 1) ? max(nums[2*i], nums[2*i+1]) : min(nums[2*i], nums[2*i+1]));
            }
        }
        return nums[0];
    }
};