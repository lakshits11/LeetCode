class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        stack<int> s;
        
        for(int i=2*n-1;i>=0;i--)
        {
            while(!s.empty() && s.top()<=nums[i%n])
                s.pop();
            if(i<n)
            {
                ans[i] = s.empty()?-1:s.top();
            }
            s.push(nums[i%n]);
        }
        return ans;
    }
};