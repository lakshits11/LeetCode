class Solution {
public:
    int finalValueAfterOperations(vector<string>& ops) {
        int ans=0;
        for(string s : ops)
        {
            if(s[0]=='-')
                ans--;
            else if(s[0]=='+')
                ans++;
            else if(s[0]=='X')
            {
                if(s[1]=='-')
                    ans--;
                else ans++;
            }
        }
        return ans;
    }
};