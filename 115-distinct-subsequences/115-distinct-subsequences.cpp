class Solution
{
public:
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &mem)
    {
        // Base Case: If all characters of s2 are matched, then return 1
        if (j < 0)
            return 1;
        if (i < 0)
            return 0;
        if (mem[i][j] != -1)
            return mem[i][j];
        if (s1[i] == s2[j])
            return mem[i][j] = f(i - 1, j, s1, s2, mem) + f(i - 1, j - 1, s1, s2, mem);
        else
            return mem[i][j] = f(i - 1, j, s1, s2, mem);
    }

    int numDistinct(string s, string t)
    {
        int n = s.length(), m = t.length();
        vector<vector<int>> mem(n, vector<int>(m, -1));
        return f(n - 1, m - 1, s, t, mem);
    }
};