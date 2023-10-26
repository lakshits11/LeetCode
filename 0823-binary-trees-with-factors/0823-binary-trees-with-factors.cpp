class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        sort(arr.begin(), arr.end());
        unordered_map<int, long long> u;
        for(int i:arr) u[i]=1;
        for(int i:arr)
        {
            for(int j:arr)
            {
                if(i==j) break;
                if(i%j==0 && u.count(i/j))
                    u[i] += (u[j]*u[i/j]);
            }
        }
        int ans=0;
        for(auto i : arr)
        {
            ans = (ans + u[i])%1000000007;
        }
        return ans;
        
    }
};