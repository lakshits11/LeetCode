// https://leetcode.com/problems/maximum-compatibility-score-sum/solutions/1360805/backtracking-with-stl-10-lines-of-code-c
class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& st, vector<vector<int>>& mt) 
    {
        int ans = 0;
        vector<int> pos(st.size());
        for(int i=0;i<st.size();++i)
            pos[i]=i;
        do {
            int curr = 0;
            for(int i = 0; i < st.size(); ++i)
            {
                for(int j = 0; j < st[pos[i]].size(); ++j)
                {
                    curr += (st[pos[i]][j] == mt[i][j]);
                }   
            }
            ans = max(ans, curr);
        } while (next_permutation(pos.begin(), pos.end()));
        
        return ans;
    }
};