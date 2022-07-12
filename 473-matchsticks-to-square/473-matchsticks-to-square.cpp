class Solution {
private:
    bool dfs(vector<int> &sides, vector<int> &nums, int index, int &target)
    {
        if(index == nums.size())
            return sides[0]==sides[1] && sides[1]==sides[2] && sides[2]==sides[3];
        for(int i = 0; i<4; i++)
        {
            if(sides[i] + nums[index] > target)
                continue;
            int j = i;
            while(--j >= 0)
            {
                if(sides[i]==sides[j])
                    break;
            }
            if(j != -1)
                continue;

            sides[i] += nums[index];
            if(dfs(sides, nums, index+1, target))
                return true;
            sides[i] -= nums[index];
        }
        return false;
        
    }
public:
    bool makesquare(vector<int>& nums)
    {
        ios_base::sync_with_stdio(false);
        sort(nums.begin(), nums.end(), greater<int>());
        int target = accumulate(nums.begin(), nums.end(), 0);
        // for(int &num : nums)
        // {
        //     if(num > target)
        //         return false;
        // }
        if(nums.empty() || target % 4 != 0 )
            return false;
        target /= 4;
        vector<int> sides(4, 0);
        return dfs(sides, nums, 0, target);
    }
};