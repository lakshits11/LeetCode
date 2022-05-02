class Solution
{
public:
    int extend(string &s, int left, int right)
    {
        int result = 0;
        while (left >= 0 && right < s.size() && s[left--] == s[right++])
            result++;
        return result;
    }

    int countSubstrings(string s)
    {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);
        int idx = 0, res = 0, n = s.size();
        while (idx < s.size())
        {
            int front = idx;
            while (idx < n && s[idx] == s[front])
                idx += 1;
            int centerLen = idx - front;
            res += (centerLen + 1) * centerLen / 2;
            int extendLen = extend(s, front - 1, idx);
            res += extendLen;
        }
        return res;
    }
};