class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size(), s=0;
        int total = accumulate(nums.begin(), nums.end(), 0);
        int target = total-k;
        if(target==0)
            return n;
        
        unordered_map<int, int> u;
        u[0]=-1;
        int res=  INT_MIN;
        for(int i=0;i<n;i++)
        {
            s+=nums[i];
            if(u.find(s-target) != u.end())
                res = max(i-u[s-target], res);
            u[s]=i;
        }
        
        if(res==INT_MIN)
            return -1;
        
        return n-res;
    }
};