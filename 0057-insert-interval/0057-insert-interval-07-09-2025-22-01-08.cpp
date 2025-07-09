class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& it, vector<int>& ni) {
        vector<vector<int>> ans;
        if(it.size() == 0)
        {
            ans.push_back(ni);
            return ans;
        }

        int i=0, n=it.size();
        while(i<n && it[i][1]<ni[0])
        {
            ans.push_back(it[i++]);
        }

        while(i<n && it[i][0]<=ni[1])
        {
            ni[1] = max(ni[1], it[i][1]);
            ni[0] = min(ni[0], it[i][0]);
            i++;
        }
        ans.push_back(ni);
        while(i<n) ans.push_back(it[i++]);
        return ans;
    }
};