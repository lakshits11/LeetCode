class Solution {
public:
    int minDistance(string s1, string s2) {
        ios_base::sync_with_stdio(0);
        int m = s1.length(), n = s2.length();
        vector<int> prev(n+1, 0), temp(n+1, 0);

        for(int j=1;j<=n;j++)
            prev[j]=j;
        
        for(int i=1;i<=m;++i)
        {
            temp[0] = i;
            for(int j=1;j<=n;++j)
            {
                if(s1[i-1]==s2[j-1])
                    temp[j]= prev[j-1];
                else
                    temp[j] = 1 + min({prev[j], prev[j-1], temp[j-1]});
            }
            prev = temp;
        }
        
        return prev[n];
    }
};