// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//Function to find the maximum possible amount of money we can win.

class Solution{
public:

    int f(vector<vector<int>> &dp, int arr[], int i, int j)
    {
        if(i>j)
            return 0;
        if(i==j)
            return arr[i];
        if(j==i+1)
            return max(arr[i], arr[j]);
        if(dp[i][j] != -1)
            return dp[i][j];
        int x = f(dp, arr,i+1, j-1);
        int opt1 = arr[i] + min(f(dp, arr,i+2, j), x);
        int opt2 = arr[j] + min( x, f(dp,arr, i,j-2));
        return dp[i][j] = max(opt1, opt2);
    }

    long long maximumAmount(int arr[], int n){
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return f(dp,arr,0,n-1);
    }
};

// class Solution
// {
// public:
//     long long int dp[1001][1001];
//     long long maximumAmount(int arr[], int n)
//     {
//         memset(dp, -1, sizeof(dp));
//         return getMe(0, n - 1, arr);
//     }
//     long long int getMe(int start, int end, int arr[])
//     {
//         if (start > end)
//             return 0;
//         if (start == end)
//             return arr[start];
//         if (start == end + 1)
//             return max(arr[start], arr[end]);
//         if (dp[start][end] != -1)
//             return dp[start][end];
//         // i can either take vi and min of i+1...j or vj and min of i...j-1;
//         dp[start][end] = max(arr[start] + min(getMe(start + 2, end, arr), getMe(start + 1, end - 1, arr)), arr[end] + min(getMe(start + 1, end - 1, arr), getMe(start, end - 2, arr)));
//         return dp[start][end];
//     }
// };




// { Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends