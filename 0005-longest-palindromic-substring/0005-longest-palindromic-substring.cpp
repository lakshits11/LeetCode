class Solution
{
public:
    string longestPalindrome(string s)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int mxLength = 1;
        int start = 0;
        int len = s.length();

        int low, high;

        for (int i = 1; i < len; i++)
        {
            low = i - 1;
            high = i;

            while (low >= 0 and high < len and s[low] == s[high])
            {
                if (high - low + 1 > mxLength)
                {
                    start = low;
                    mxLength = high - low + 1;
                }
                --low;
                ++high;
            }

            low = i - 1;
            high = i + 1;

            while (low >= 0 and high < len and s[low] == s[high])
            {
                if (high - low + 1 > mxLength)
                {
                    start = low;
                    mxLength = high - low + 1;
                }
                --low;
                ++high;
            }
        }

        return s.substr(start, mxLength);
    }
};