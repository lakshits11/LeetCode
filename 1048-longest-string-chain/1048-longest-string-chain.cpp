class Solution {
public:
    int longestStrChain(vector<string>& words) {
        ios_base::sync_with_stdio(false);
        int res = 1;
        unordered_map<string, int> dp;
        sort(words.begin(), words.end(), []
        (const std::string& first, const std::string& second){
            return first.size() < second.size();
        });
        
        for(string word : words)
        {
            dp[word]=1;
            for(int i=0;i<word.size();++i)
            {
                string prev = word.substr(0,i) + word.substr(i+1);
                if(dp.find(prev)!=dp.end())
                {
                    dp[word] = max(dp[word], dp[prev]+1);
                    res = max(res, dp[word]);
                }
            }
        }
        
        return res;
        
        
        
    }
};