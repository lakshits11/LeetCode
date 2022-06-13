// By Lakshit Somani
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n+1][5];
        memset(dp, 0, sizeof(dp));
        // for(int i=0;i<=4;i++)
        //     dp[n][i] = 0;
        // for(int i=0;i<=n;i++)
        //     dp[i][4]=0;
        
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int tr=3;tr>=0;tr--)
            {
                if(tr%2==0)
                    dp[ind][tr] = max(-prices[ind] + dp[ind+1][tr+1], dp[ind+1][tr]);
                else
                    dp[ind][tr] = max(prices[ind] + dp[ind+1][tr+1], dp[ind+1][tr]);
            }
        }
        
        return dp[0][0];
    }
};