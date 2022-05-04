class Solution {
public:
    vector<vector<string>> partition(string s) {
        int len = s.length();
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        vector<vector<string>> res;
        vector<string> curr;
        dfs(res, s, 0, curr, dp);
        return res;
    }
    
    void dfs(vector<vector<string>> &res, string &s, int start, vector<string> &curr, vector<vector<bool>> &dp)
    {
        if(start>=s.length())
            res.push_back(curr);
        for(int end=start;end<s.length();end++){
            if(s[start]==s[end] && (end-start<=2 || dp[start+1][end-1]))
            {
                dp[start][end]=true;
                curr.push_back(s.substr(start, end-start+1));
                dfs(res,s,end+1,curr,dp);
                curr.pop_back();
            }
        }
    }
};