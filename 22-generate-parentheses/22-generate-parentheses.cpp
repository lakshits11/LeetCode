// By Lakshit Somani
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution
{
public:
    void backtrack(vector<string> &ans, string str, int open, int close, int max)
    {
        if (str.length() == 2 * max)
        {
            ans.push_back(str);
            return;
        }

        if (open < max)
            backtrack(ans, str + "(", open + 1, close, max);
        if (close < open)
            backtrack(ans, str + ")", open, close + 1, max);
    }

    vector<string> generateParenthesis(int n)
    {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);
        vector<string> ans;
        backtrack(ans, "", 0, 0, n);

        return ans;
    }
};