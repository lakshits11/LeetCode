// By Lakshit Somani
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        multiset<int> st;
        vector<pair<int, int>> vec;
        vector<vector<int>> res;
        for (int i = 0; i < buildings.size(); ++i)
        {
            vec.push_back({buildings[i][0], buildings[i][2]});
            vec.push_back({buildings[i][1], -buildings[i][2]});
        }
        sort(vec.begin(), vec.end());
        int i = 0;
        st.insert(0);
        int maxe = 0;
        while (i < vec.size())
        {
            int start = vec[i].first;
            while (i < vec.size() && vec[i].first == start)
            {
                if (vec[i].second > 0)
                    st.insert(vec[i].second);
                else
                {
                    auto it = st.lower_bound(-vec[i].second);
                    st.erase(it);
                }
                i++;
            }
            if (*st.rbegin() != maxe)
            {
                maxe = *st.rbegin();
                res.push_back({start, maxe});
            }
        }
        return res;
    }
};