class Solution {
public:
    unordered_map<int, int> dp;
    
    int traverse(int i)
    {
        if(dp[i] || i==1)
            return dp[i];
        
        if(i%2==0)
            dp[i] = 1 + traverse(i/2);
        else
            dp[i] = 1 + traverse(3*i + 1);
        
        return dp[i];
    }
    
    int getKth(int lo, int hi, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<pair<int, int>> v;
        for(int i=lo;i<=hi;i++)
        {
            v.push_back({traverse(i), i});
        }
        sort(v.begin(), v.end());
        return v[k-1].second;
    }
    
    
};