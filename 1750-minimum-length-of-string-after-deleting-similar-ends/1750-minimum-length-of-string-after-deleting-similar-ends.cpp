class Solution {
public:
    int f(string &s, int i, int j, int &n)
    {
        if(i>j || i>n-1 || j<0) return 0;
        if(i==j)   return 1;
        char x = s[i];
        char y = s[j];
        if(x!=y)
            return (j-i+1);
        while(i<=n-1 && s[i]==x)
            i++;
        while(j>=0 && s[j]==y)
            j--;
        return f(s, i, j, n);
    }
    
    int minimumLength(string s)
    {
        int n = s.size();
        int i = 0, j = n-1;
        return f(s, 0, n-1, n);
    }
};