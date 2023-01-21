bool isValid(string s)
{
    if (s.length() > 3 || s.empty())
        return false;

    // 0 is valid but starting with 0 and length greater than 1, like 00, 01, 023...arenot valid.
    if (s[0] == '0' and s.length() > 1)
        return false;

    int val = stoi(s);

    return (val >= 0 and val <= 255);
}

class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> result;

        int n = s.length();
        if (n >= 13)
            return {};

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    string a = s.substr(0, i);
                    string b = s.substr(i, j - i);
                    string c = s.substr(j, k - j);
                    string d = s.substr(k);

                    if (isValid(a) and isValid(b) and isValid(c) and isValid(d))
                    {
                        string ip = a + "." + b + "." + c + "." + d;
                        result.push_back(ip);
                    }
                }
            }
        }

        return result;
    }
};