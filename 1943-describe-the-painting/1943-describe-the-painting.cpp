class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& sg) {
        ios_base::sync_with_stdio(false);
        map<int, long long> mp;
        for(int i=0; i<sg.size(); i++)
        {
            mp[sg[i][0]] += sg[i][2];
            mp[sg[i][1]] -= sg[i][2];
        }
        int prev = -1;
        long long color = 0;
        vector<vector<long long>> res;
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            if(prev != -1 && color != 0)
            {
                res.push_back({prev, it->first, color});
            }
            prev = it->first;
            color += it->second;
        }
        return res;
    }
};