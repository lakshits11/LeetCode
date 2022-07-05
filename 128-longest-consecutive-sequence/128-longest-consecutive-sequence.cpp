class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> u;
        int longestStreak = 0;
        for(int i=0;i<nums.size();i++)
        {
            u.insert(nums[i]);
        }
        for(int num : u)
        {
            if(u.find(num-1) == u.end())
            {
                int currNum = num;
                int currStreak = 1;
                while(u.find(currNum+1) != u.end()) {
                    currNum += 1;
                    currStreak += 1;
                }
                longestStreak = max(longestStreak, currStreak);
            }
        }
        return longestStreak;
    }
};