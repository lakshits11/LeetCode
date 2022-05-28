class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(false);
        vector<int> ans;
        int count=0;
        for(auto p : queries)
        {
            for(auto c : points)
            {
                if((p[0]-c[0])*(p[0]-c[0]) + (p[1]-c[1])*(p[1]-c[1]) <= (p[2]*p[2]))
                    count++;
            }
            ans.push_back(count);
            count=0;
        }
        return ans;
    }
};