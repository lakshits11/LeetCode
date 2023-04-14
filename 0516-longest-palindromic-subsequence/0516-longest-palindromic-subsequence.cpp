class Solution {
public:
    int f(int l, int r, string &s, vector<vector<int>> &mem)
    {
        if(mem[l][r]!=-1)
            return mem[l][r];
        if(l==r)
            return mem[l][r]=1;
        if(l>r)
            return 0;
        if(s[l]==s[r])
            return mem[l][r] = 2+f(l+1, r-1, s, mem);
        else
            return mem[l][r] = max(f(l+1, r, s, mem), f(l, r-1, s, mem));
        return mem[l][r];
    }
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> mem(n, vector<int>(n,-1));
        return f(0,n-1,s,mem);
    }
};