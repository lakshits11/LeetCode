class Solution {
public:
    int f(int i, int j, string &s, vector<vector<int>> &mem)
    {
        if(i==j || i>j)    return 0;
        if(mem[i][j]!=-1)
            return mem[i][j];
        if(s[i]==s[j])
            return mem[i][j] = f(i+1, j-1, s, mem);
        else
            return mem[i][j] = 1 + min(f(i+1, j, s, mem), f(i, j-1, s, mem));
    }
    
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> mem(n, vector<int>(n, -1));
        return f(0, n-1, s, mem);
    }
};