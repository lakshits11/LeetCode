class Solution {
public:
    bool backspaceCompare(string s, string t) {
        ios_base::sync_with_stdio(false);
        stack<char> s1;
        stack<char> s2;
        int n = s.size();
        int m = t.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]!='#')
            {
                s1.push(s[i]);
            }
            else
            {
                if(!s1.empty())
                    s1.pop();
            }
        }
        for(int i=0;i<m;i++)
        {
            if(t[i]!='#')
            {
                s2.push(t[i]);
            }
            else
            {
                if(!s2.empty())
                    s2.pop();
            }
        }
        while(!s1.empty() and !s2.empty())
        {
            if(s1.top()!=s2.top())
                return false;
            else{
                s1.pop();s2.pop();
            }
        }
        if((!s1.empty() and s2.empty()) || (s1.empty() and !s2.empty()) )
            return false;
        return true;
    }
};