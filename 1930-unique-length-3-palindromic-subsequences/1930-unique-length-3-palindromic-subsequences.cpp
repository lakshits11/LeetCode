class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> ss;
        for(char &c : s)
            ss.insert(c);
        
        int ans = 0;
        for(char c : ss)
        {
            int i = -1, j = 0;
            
            for(int k = 0; k < s.size(); k++)
            {
                if(s[k] == c){
                    if(i==-1) i=k;
                    j=k;
                }
            }
            
            unordered_set<char> bw;
            for(int k = i+1; k < j; k++)
                bw.insert(s[k]);
            ans += bw.size();
        }
        return ans;
    }
};