class Solution {
public:
    bool check(string s1, string s2)
    {
        if(s1.size()>s2.size()) return false;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i]) return false;
        }
        int j = s2.size()-1;
        for(int i=s1.size()-1;i>=0;i--)
        {
            if(s1[i]!=s2[j--])
                return false;
        }
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans=0;
        for(int i=0;i<words.size();i++)
        {
            for(int j=i+1;j<words.size();j++)
            {   
                if(check(words[i], words[j])) ans++;
            }
        }
        return ans;
    }
};