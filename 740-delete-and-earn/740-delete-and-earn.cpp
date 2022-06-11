class Solution {
public:
    
    unordered_map<int, int> mem;
    unordered_map<int, int> points;
    
    int f(int i)
    {
        if(i==0)    return 0;
        if(i==1)    return points[1];
        if(mem.find(i)!=mem.end())
            return mem[i];
        
        return mem[i] = max(f(i-1), points[i]+f(i-2));
    }
    
    int deleteAndEarn(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        int n = nums.size(), maxn = INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            points[nums[i]]+=nums[i];
            maxn = max(maxn, nums[i]);
        }
        
        return f(maxn);
        
    }
};