// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#define m 1000000007
class Solution{
    public:
    int Maximize(int a[],int n)
    {
        // Complete the function
        long long product = 0;
        sort(a,a+n);
        for(int i=1; i<n; i++) {
           product = product + ((long long int)a[i]*i);
           product = product % m;
        }
        return product;
    }
};

// { Driver Code Starts.
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<<ob.Maximize(a,n)<<endl;
    }
}  // } Driver Code Ends