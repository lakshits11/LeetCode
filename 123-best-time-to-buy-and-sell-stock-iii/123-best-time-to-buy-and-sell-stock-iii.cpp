// By Lakshit Somani
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:    
    int maxProfit(vector<int>& prices) {
        ios_base::sync_with_stdio(false);
        int n = prices.size();
        int dp[5];
        memset(dp, 0, sizeof(dp));
        
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int tr=3;tr>=0;tr--)
            {
                if(tr%2==0)
                    dp[tr] = max(-prices[ind] + dp[tr+1], dp[tr]);
                else
                    dp[tr] = max(prices[ind] + dp[tr+1], dp[tr]);
            }
        }
        
        return dp[0];
    }
};