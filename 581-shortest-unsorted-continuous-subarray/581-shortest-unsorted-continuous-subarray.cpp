class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int minn=INT_MAX,maxx=INT_MIN, n=nums.size();
        for(int i=0;i<n-1;i++)
            if(nums[i]>nums[i+1])
                minn = min(nums[i+1], minn);
        for(int i=n-1;i>0;i--)
            if(nums[i-1]>nums[i])
                maxx = max(nums[i-1], maxx);
        
        int i=0;
        for(;i<n;++i)
            if(nums[i]>minn)
                break;
        
        int j=n-1;
        for(;j>=0;--j)
            if(nums[j]<maxx)
                break;
        
        return i>j ? 0 : j-i+1;
    }
};