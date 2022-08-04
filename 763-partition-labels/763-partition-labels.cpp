// By Lakshit Somani
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int mp[26] = {};
        for (int i = 0; i < s.size(); i++)
            mp[s[i] - 'a'] = i;

        vector<int> res;
        int prev = -1, maxi = 0;

        for (int i = 0; i < s.size(); i++)
        {
            maxi = max(maxi, mp[s[i]-'a']);
            if (maxi == i)
            {
                res.push_back(maxi - prev);
                prev = maxi;
            }
        }
        return res;
    }
};