class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int mod = 1e9+7;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        long dp[n];
        for(int i=0;i<n;i++)
            dp[i] = 1;
        
        unordered_map<int, int> u;
        for(int i=0;i<n;i++)
            u[arr[i]] = i;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[i] % arr[j] == 0) {
                    int right = arr[i]/arr[j];
                    if(u.find(right)!=u.end())
                    {
                        dp[i] = (dp[i] + dp[j]*dp[u[right]])%mod;
                    }
                }
            }
        }
        
        long ans = 0;
        for(long x : dp)
            ans += x;
        return ans%mod;
    }
};