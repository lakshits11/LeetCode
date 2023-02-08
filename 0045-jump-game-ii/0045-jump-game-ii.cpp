class Solution {
public:
    int jump(vector<int>& nums)
    {
        int n = nums.size();
        int l = 0, r = 0;
        int count=0;
        while(r < n-1 && l<n-1)
        {
            int farthest=0;
            for(int i=l;i<=r;i++)
                farthest = max(farthest, i+nums[i]);
            if(farthest==0) return -1;
            l = r+1;
            r = farthest;
            count++;
        }
        return count;
    }
};