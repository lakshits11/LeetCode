class Solution {
public:
    vector<string> ans;
    void dfs(int i, string s)
    {
        if(i==s.size()){
            ans.push_back(s);
            return;
        }
        
        char c = s[i];
        s[i] = islower(c) ? toupper(c) : tolower(c);
        dfs(i+1, s);
        
        // now if s[i] wasnt a digit, , we need to toggle it back
        if(isalpha(c))
        {
            s[i]=c;
            dfs(i+1, s);
        }
    }
        
    vector<string> letterCasePermutation(string s) {
        dfs(0, s);
        return ans;
    }
};