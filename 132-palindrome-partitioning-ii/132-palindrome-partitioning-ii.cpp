class Solution {
private:
    vector<int> dp;
    vector<vector<bool>> pal;
    
    int f(int i, string &s)
    {
        if(i == s.size())
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int minCost = INT_MAX;
        // string temp = "";
        for(int j = i; j < s.size(); j++)
        {
            // temp += s[j];
            if(s[i] == s[j] && (j - i <= 2 || pal[i+1][j-1]))
            {
                pal[i][j] = true;
                int cost = 1 + f(j+1, s);
                minCost = min(minCost, cost);
            }
        }
        return dp[i] = minCost;
    }
    
public:
    int minCut(string s) {
        int n = s.size();
        dp.resize(n, -1);
        pal.resize(n, vector<bool>(n, false));
        return f(0, s) - 1;
    }
};