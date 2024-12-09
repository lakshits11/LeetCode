// class Solution {
// public:
//     vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& q) 
//     {
//         int n = nums.size();
//         vector<bool> ans(q.size(), false);
//         vector<int> p(n, 0);
//         p[0] = 1;
//         for(int i=1;i<n;i++)
//         {
//             if((nums[i]%2 ^ nums[i-1]%2) == 1)
//                 p[i]=1;
//             p[i]+=p[i-1];
//         }
//         for(int i=0;i<q.size();i++)
//         {
//             if((q[i][1]-q[i][0]) == (p[q[i][1]]-p[q[i][0]]))
//                 ans[i] = true;
//         }
//         return ans;
//     }
// };

static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& q) 
    {
        int n = nums.size();
        vector<bool> ans(q.size(), false);
        vector<int> p(n, 0);
        p[0] = 1;
        for(int i=1;i<n;i++)
        {
            p[i] = nums[i]%2 ^ nums[i-1]%2;
            p[i]+=p[i-1];
        }
        for(int i=0;i<q.size();i++)
        {
            if((q[i][1]-q[i][0]) == (p[q[i][1]]-p[q[i][0]]))
                ans[i] = true;
        }
        return ans;
    }
};