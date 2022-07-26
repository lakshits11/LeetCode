class Solution {
private:
    int atmost(vector<int> nums, int k)
    {
        int i=0;
        int j=0;
        int count=0;
        map<int, int> m;
        while(i < nums.size())
        {
            m[nums[i]]++;
            while(m.size()>k)
            {
                m[nums[j]]--;
                if(m[nums[j]] == 0)
                    m.erase(nums[j]);
                j++;
            }
            count += (i-j+1);
            i++;
        }
        return count;
        
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k)
    {
        return (atmost(nums,k) - atmost(nums,k-1));
    }
};