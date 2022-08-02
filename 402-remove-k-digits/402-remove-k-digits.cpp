class Solution {
public:
    string removeKdigits(string num, int k)
    {
        string s;
        for(int i=0;i<num.size();++i)
        {
            while(!s.empty() && s.back()>num[i] && k>0)
            {
                s.pop_back();
                k--;
            }
            s.push_back(num[i]);   
        }
        int i=0;
        while(k>0)
        {
            s.pop_back();
            k--;
        }
        while(i<s.size() && s[i]=='0')
            i++;
        if(i==s.size())
            return "0";
        return s.substr(i);
    }
};