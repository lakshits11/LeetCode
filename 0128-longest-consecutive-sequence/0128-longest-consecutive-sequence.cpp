class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);
        int n = nums.size();
        unordered_map<int, bool> u;
        for(int i=0;i<n;++i)
        {
            u[nums[i]] = true;
        }
        for(int i=0;i<n;++i)
        {
            if(u.count(nums[i]-1)>0) u[nums[i]] = false;
        }
        int ans = 0;
        for(int i=0;i<n;++i)
        {
            if(u[nums[i]])
            {
                int j=0, count = 0;
                while(u.count(nums[i]+j)>0) // i.e. if nums[i]+j exists in array
                {
                    ++j;
                    ++count;
                }
                if(count > ans)
                    ans = count;
            }
        }
        return ans;
    }
};