static const auto speedup = []() -> int
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> count;
        int minJ = INT_MAX, minI = 1, i = 0;
        for (int i = 0; i < t.size(); ++i)
        {
            count[t[i]]++;
        }
        // count of remaining chars needed to be present in string s
        int remaining = count.size();
        for (int j = 0; j < s.size(); ++j)
        {
            count[s[j]]--;

            if (count[s[j]] == 0) remaining--; // that means the count of s[j] in current window has equaled to count of s[j] in t. So we have one less character to process. Hence remaining is decreased by one.
            while (remaining == 0)
            {
                if (j - i < minJ - minI)
                {
                    minJ = j, minI = i;
                }
                // remove i from window and increment i
                count[s[i]]++;
                if (count[s[i]] > 0) remaining++;
                i++;
            }
        }
        return minJ == INT_MAX ? "" : s.substr(minI, minJ - minI + 1);
    }
};