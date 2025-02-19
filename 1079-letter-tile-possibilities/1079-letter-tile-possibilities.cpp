class Solution
{
public:
    vector<int> freq;
    int backtrack()
    {
        int res = 0;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] > 0)
            {
                --freq[i];
                res++;
                res += backtrack();
                ++freq[i];
            }
        }
        return res;
    }
    int numTilePossibilities(string tiles)
    {
        freq.resize(26, 0);
        for (char &c : tiles)
            freq[c - 'A']++;
        return backtrack();
    }
};