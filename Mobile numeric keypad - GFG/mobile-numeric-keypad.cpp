// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
private:
    vector<vector<int>> path = {{0,8}, {1,2,4}, {2,1,3,5}, {3,2,6}, {4,1,5,7}, {5,2,4,6,8}, {6,5,3,9}, {7,4,8}, {8,5,7,9,0}, {9,8,6}};
    vector<vector<long long>> dp;
    long long f(long long digit, int n)
    {
        if(n==1)
        {
            if(digit==0)    return 2;
            else if(digit == 5 || digit == 8)
                return 5;
            else if(digit== 2 || digit==4 || digit== 6)
                return 4;
            else return 3;
        }
        if(dp[digit][n] != -1)
            return dp[digit][n];
        long long ans = f(path[digit][0], n-1) + f(path[digit][1], n-1);
        if(digit != 0)
        {
            ans += f(path[digit][2], n-1);
        }
        if(digit == 2 || digit==4 || digit == 6 || digit == 5 || digit==8)
        {
            ans += f(path[digit][3], n-1);
        }
        if(digit==5 || digit==8)
        {
            ans += f(path[digit][4], n-1);
        }
        return dp[digit][n] = ans;
    }
    
public:
	long long getCount(int N)
	{
	    dp.resize(10, vector<long long>(N+1, -1));
	    long long ans = 0;
	    if(N == 1)
    	    return 10;
		for(int i = 0; i < 10; i++)
		{
		    ans += f(i, N-1);
		}
		return ans;
	}
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends