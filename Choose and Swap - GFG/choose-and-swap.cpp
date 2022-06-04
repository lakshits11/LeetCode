// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    string chooseandswap(string a){
        int i, j, n=a.length();
        int chk[26];
        for(i=0;i<26;i++)
            chk[i]=-1;
        for(i=0; i<n; i++)
        {
            if(chk[a[i]-'a']==-1)
                chk[a[i]-'a'] = i;
        }
        
        for(i=0; i<n; i++)
        {
            bool flag = false;
            for(j=0;j<(a[i]-'a');j++)
            {
                if(chk[j] > chk[a[i]-'a']){
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }
        
        // If swapping is possible
        if(i<n)
        {
            char c1 = a[i];
            char c2 = char(j+'a');
            for(i=0;i<n;i++)
            {
                if(a[i]==c1)
                    a[i]=c2;
                else if(a[i]==c2)
                    a[i]=c1;
            }
        }
        
        return a;
    }
    
};


// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
  // } Driver Code Ends