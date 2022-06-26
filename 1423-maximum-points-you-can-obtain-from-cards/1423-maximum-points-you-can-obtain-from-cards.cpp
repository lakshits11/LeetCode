class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int len = c.size();
        int totalSum = accumulate(c.begin(), c.end(), 0);
        int x = len - k;
        if(x==0)    return totalSum;
        int cs = 0, ms = 0;
        for(int i=0;i<x;i++)
        {
            cs += c[i];
        }
        ms = cs;
        for(int i=x;i<len;i++)
        {
            cs += c[i]-c[i-x];
            ms = min(ms, cs);
        }
        return totalSum - ms;
        
        
    }
};