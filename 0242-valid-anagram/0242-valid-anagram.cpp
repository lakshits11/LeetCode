class Solution {
public:
    bool isAnagram(string s, string t) {
        int a[26]={0};
        int b[26]={0};
        for(char &c : s)
            a[c-'a']++;
        for(char &c : t)
            b[c-'a']++;
        for(int i=0;i<26;i++)
        {
            if(a[i]!=b[i]) return false;
        }
        return true;
    }
};