// By Lakshit Somani
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    map<string, bool> m;
    bool isPal(string &s)
    {
        if (m.find(s) != m.end())
            return m[s];
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            if (s[i++] == s[j--])
                continue;
            else
                return m[s] = false;
        }
        return m[s] = true;
    }

public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        int n = words.size();
        vector<vector<int>> ans;
        unordered_map<string, int> u;
        for (int i = 0; i < words.size(); i++)
        {
            string s = words[i];
            reverse(s.begin(), s.end());
            u[s] = i;
        }
        if (u.find("") != u.end())
        {
            for (int i = 0; i < words.size(); i++)
            {
                if (i == u[""])
                    continue;
                if (isPal(words[i]))
                    ans.push_back({i, u[""]});
            }
        }

        for(int i=0;i<words.size();i++)
        {
            string r = words[i];
            string l = "";
            for(int j=0;j<words[i].size();j++)
            {
                l.push_back(words[i][j]);
                r.erase(0, 1);
                if(u.find(l) != u.end() && isPal(r) && u[l]!=i)
                    ans.push_back({i, u[l]});
                if(u.find(r) != u.end() && isPal(l) && u[r]!=i)
                    ans.push_back({u[r], i});
            }
        }
        return ans;
    }
};