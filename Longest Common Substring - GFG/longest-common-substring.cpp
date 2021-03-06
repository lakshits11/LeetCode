// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        int temp[m+1];
        int maxi = 0;
        memset(temp, 0, sizeof(temp));
        
        for(int i=1;i<=n;i++)
        {
            for(int j=m;j>=1;j--)
            {
                if(s1[i-1]==s2[j-1])
                    temp[j] = 1+temp[j-1];
                else
                    temp[j] = 0;
                maxi = max(maxi, temp[j]);
            }
        }
        
        return maxi;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends