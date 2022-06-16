// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
public:
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n + 1, -1);
        dp[0]=0;
        int coin[3];
        coin[0] = x, coin[1] = y, coin[2] = z;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (i >= coin[j] && dp[i-coin[j]]!=-1)
                    dp[i] = max(dp[i], 1 + dp[i - coin[j]]);
            }
        }
        if(dp[n]==-1)  return 0;
        return dp[n];
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends