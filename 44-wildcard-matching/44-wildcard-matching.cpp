class Solution {
public:
    bool isMatch(string s2, string s1) {
        ios_base::sync_with_stdio(false);
        int n = s1.length(), m = s2.length(), k;
        bool prev[m+1], temp[m+1];
        // prev is 0th row. So anywhere we see dp[0][j] => directly replace it with prev[j]
        memset(prev, false, sizeof(prev));
        memset(temp, false, sizeof(temp));
        
        prev[0] = true;
        
        for(int j=1;j<=m;++j)   prev[j]=false;
        
        // for every row, you are assigning 0th column value
        /*for(int i=1;i<=n;i++)
        {
            if(s1[i-1]=='*' && dp[i-1][0]==true)
                dp[i][0]=true;
            else
                dp[i][0]=false;
        }*/
        
        for(int i=1;i<=n;++i)
        {
            if(s1[i-1]=='*' && prev[0]==true)
                temp[0]=true;
            else
                temp[0]=false;
            for(int j=1;j<=m;++j)
            {
                if (s1[i-1] == s2[j-1] || s1[i-1] == '?')
                    temp[j] = prev[j - 1];
                else if(s1[i-1]=='*')
                    temp[j] = prev[j] || temp[j-1];
                else
                    temp[j] = false;
            }
            for(k=0;k<=m;++k)
                prev[k] = temp[k];
        }
        
        return prev[m];
    }
};