class Solution
{
public:
    string smallestNumber(string pattern)
    {
        string ans;
        stack<int> s;
        for (int i = 0; i <= pattern.size(); i++)
        {
            s.push(i + 1);
            if (i == pattern.size() || pattern[i] == 'I')
            {
                while (!s.empty())
                {
                    ans += to_string(s.top());
                    s.pop();
                }
            }
        }
        return ans;
    }
};