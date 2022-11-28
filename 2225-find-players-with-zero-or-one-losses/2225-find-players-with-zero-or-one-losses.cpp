class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& mt) {
        unordered_map<int, int> m;
        set<int> s;
        for(int i = 0; i < mt.size(); i++)
        {
            s.insert(mt[i][0]);
            s.insert(mt[i][1]);
            m[mt[i][1]]++;
        }
        vector<vector<int>> ans(2);
        for(int i : s)
        {
            if(m.find(i) != m.end() && m[i] == 1)
                ans[1].push_back(i);
            else if(m.find(i)==m.end())
                ans[0].push_back(i);
        }
        return ans;
    }
};