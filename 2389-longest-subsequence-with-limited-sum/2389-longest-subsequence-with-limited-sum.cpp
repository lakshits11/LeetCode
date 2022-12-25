class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i=1;i<nums.size(); i++)
        {
            nums[i] += nums[i-1];
        }
        for(int i = 0; i  < queries.size(); i++)
        {
            int k = queries[i], x = 0;
            // int indans = nums.size(), s = 0;
            for(x=0;x<nums.size();x++)
            {
                if(nums[x]>k)
                {
                    break;
                }
            }
            ans.push_back(x);
        }
        return ans;
    
    }
};