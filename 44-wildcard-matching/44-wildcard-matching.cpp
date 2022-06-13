class Solution {
public:
    bool f(int i, int j, string &s1, string &s2, vector<vector<int>> &mem ) {
        if (i < 0 && j < 0)
            return true;
        if (i < 0 && j >= 0)
            return false;
        // When s2 is empty and s1 still has some characters left
        // it has to be all stars (since only stars match with empty chars) else we return false. 
        if (j < 0 && i >= 0)
        {
            for (int k = 0; k <= i; k++)
                if (s1[k] != '*')
                    return false;

            return true;
        }
        if(mem[i][j]!=-1)
            return mem[i][j];
        if (s1[i] == s2[j] || s1[i] == '?')
            return mem[i][j] = f(i - 1, j - 1, s1, s2, mem);

        // Star: 2 Cases
        // 1. Assuming star means nothing
        // 2. Star means one character and again check for remaning s2(j becoming j-1) and s1 (with star intact as before)
        if (s1[i] == '*')
            return mem[i][j] = f(i - 1, j, s1, s2, mem) || f(i, j - 1, s1, s2, mem);

        return mem[i][j] = false;
    }
    
    bool isMatch(string s2, string s1) {
        ios_base::sync_with_stdio(false);
        int n = s1.length(), m = s2.length();
        vector<vector<int>> mem(n, vector<int>(m, -1));
        return f(n-1, m-1, s1, s2, mem);
    }
};