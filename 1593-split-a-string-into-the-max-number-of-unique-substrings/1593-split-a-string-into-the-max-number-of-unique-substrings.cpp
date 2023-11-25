class Solution {
public:
    unordered_set<string> ss;
    int ans = 0;
    
    void dfs(string &s, int ind)
    {
        if(ss.size()>ans) ans = ss.size();
        if(ind>=s.size()) return;
        string temp = "";
        for(int i=ind; i < s.size(); i++)
        {
            temp += s[i];
            if(ss.find(temp) == ss.end())
            {
                ss.insert(temp);
                dfs(s, i+1);
                ss.erase(temp);
            }
        }
    }
    int maxUniqueSplit(string s) {
        dfs(s, 0);
        return ans;
    }
};