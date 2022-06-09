class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        int i=0, j=n-1, ss = 0;
        while(i<j)
        {
            ss = nums[i]+nums[j];
            if(ss < k)
                i++;
            else if(ss > k)
                j--;
            else{
                ans.push_back(i+1);
                ans.push_back(j+1);
                return ans;
            }
        }
        return ans;
    }
};