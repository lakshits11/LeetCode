class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> word_set(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length()+1);
        dp[0]=true;
        
        // dp[i] is true if s[0..j] and s[j+1...i] both are present in dictionary
        
        for(int i=1;i<=s.length();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(dp[j] && word_set.find(s.substr(j,i-j)) != word_set.end()){
                    dp[i]=true;
                    break;
                }
            }
        }
        
        return dp[s.length()];
    }
};