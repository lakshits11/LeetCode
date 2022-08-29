class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& b) {
        multiset<int> st;
        vector<pair<int, int>> vec;
        vector<vector<int>> ans;
        
        for(int i = 0; i < b.size(); i++)
        {
            vec.push_back({b[i][0], b[i][2]});
            vec.push_back({b[i][1], -b[i][2]});
        }
        
        sort(vec.begin(), vec.end());
        int i = 0;
        st.insert(0);
        int maxi = 0;
        
        while(i < vec.size())
        {
            int start = vec[i].first;
            while(i < vec.size() && vec[i].first == start)
            {
                if(vec[i].second > 0)
                    st.insert(vec[i].second);
                else
                {
                    auto it = st.lower_bound(-vec[i].second);
                    st.erase(it);
                }
                i++;
            }
            if(*st.rbegin() != maxi)
            {
                maxi = *st.rbegin();
                ans.push_back({start, maxi});
            }
        }
        return ans;
    }
};