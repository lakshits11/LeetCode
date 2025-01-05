static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<long long int> delta(n);
        long long totalSum = 0;
        for(int i=0;i<n;++i)
            totalSum += nums[i];
        for(int i=0;i<n;i++)
        {
            delta[i] = (nums[i]^k) - nums[i];
        }
        sort(delta.begin(), delta.end(), greater<long long int>());
        // for(int x:delta)
        // cout<<x<<" ";
        // cout<<"\n";
        for(int i=0;i<n-1;i+=2)
        {
            if(totalSum + delta[i]+delta[i+1] > totalSum)
                totalSum += (delta[i]+delta[i+1]);
        }
        return totalSum;
    }
};