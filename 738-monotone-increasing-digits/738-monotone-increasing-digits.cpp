class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int i=0;
        for(i=1;i<s.size();i++)
            if(s[i]<s[i-1])
                break;
        if(i==s.size())
            return n;
        i -= 1;
        while(i>0 && s[i]==s[i-1])
            i--;
        s[i] = s[i] - 1;
        i+=1;
        for(int k=i;k<s.size();k++)
            s[k]='9';
        return stoi(s);
    }
};