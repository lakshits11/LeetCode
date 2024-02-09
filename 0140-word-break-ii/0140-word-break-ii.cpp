static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class Solution
{
public:
    unordered_set<string> dict;
    unordered_map<int, vector<string>> mp;
    int max_len = 0;

    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        for (string &str : wordDict)
        {
            dict.insert(str);
            max_len = max(max_len, (int)str.length());
        }

        return break_word(s, 0);
    }

    vector<string> break_word(const string &s, int idx)
    {
        if (mp.count(idx)) return mp[idx];

        string str;
        for (int i = idx; i < s.length() && str.length() <= max_len; ++i)
        {
            str += s[i];
            if (dict.count(str))
            {
                if (i == s.length() - 1)
                    mp[idx].push_back(str);
                else
                {
                    vector<string> vs = break_word(s, i + 1);
                    for (auto &a : vs)
                        mp[idx].push_back(str + " " + a);
                }
            }
        }
        return mp[idx];
    }
};