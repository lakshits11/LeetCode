class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& w, vector<int>& g) 
    {
        int l = g[0];
        vector<string> ans;
        ans.push_back(w[0]);
        for (int i = 1; i < g.size(); i++)
        {
            if(g[i]!=l){
                ans.push_back(w[i]);
                l = !l;
            }
            else continue;
        }
        return ans;
    }
};