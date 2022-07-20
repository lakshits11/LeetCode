class Solution {
public:
    int maxScore(string s)
    {
        ios_base::sync_with_stdio(false);
        int zero = 0, ones = 0, maxi = INT_MIN;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0')   zero++;
            else ones++;
            if(i != s.size()-1)
                maxi = max(maxi, zero-ones);
        }
        return maxi+ones;
        
    }
};