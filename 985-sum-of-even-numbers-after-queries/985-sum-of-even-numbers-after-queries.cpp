class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        vector<int> ans;
        for(int i : nums)
            if(i%2==0) sum += i;

        for(auto &q : queries)
        {
            if(nums[q[1]] % 2 == 0)
                sum -= nums[q[1]];
            nums[q[1]] += q[0];
            if(nums[q[1]] % 2 == 0)
                sum += nums[q[1]];
            ans.push_back(sum);
        }
        
        return ans;
    }
};