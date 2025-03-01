class Solution
{
public:
    vector<string> ans;
    void rec(int n, string &temp)
    {
        if (temp.size() == n)
        {
            ans.push_back(temp);
            return;
        }

        for (char c = '0'; c <= '1'; c++)
        {
            if (!temp.empty() && temp.back() == '0' && c == '0') continue;
            temp.push_back(c);
            rec(n, temp);
            temp.pop_back();
        }
    }
    vector<string> validStrings(int n)
    {
        string temp;
        rec(n, temp);
        return ans;
    }
};