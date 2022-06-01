class Solution {
public:
    int balancedStringSplit(string s) {
        int c=0;
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='L')
                c++;
            else
                c--;
            if(c==0)
                ans++;
        }
        return ans;
    }
};