class Solution {
public:
    int countSubstrings(string s, string t) {
        int ans = 0;
        for(int i=0; i < s.size(); i++)
        {
            for(int j=0; j < t.size(); j++)
            {
                int x = i, y = j, diff = 0;
                while(x<s.size() && y<t.size())
                {
                    if(s[x]!=t[y]) diff++;
                    if(diff==1)    ans++;
                    if(diff==2)    break;
                    x++, y++;
                }
            }
        }
        
        return ans;
    }
};