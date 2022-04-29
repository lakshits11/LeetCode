class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = t.length();
        int count=0;
        int m = s.length();
        int i=0,j=0;
        while(i<n){
            if(t[i]!=s[j]){
                i++;
            }
            else if(t[i]==s[j])
            {
                i++;j++;
                count++;
            }
        }
        if(i==n && count!=m)
            return false;
        return true;
    }
};