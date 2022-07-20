class Solution {
public:
    int maxScore(string s)
    {
        int n = s.size(), maxx = 0;
        vector<int> pref(n+1,0), suff(n+1,0);
        for(int i=0;i<n;i++)
        {
            cout << "Reaching " << i << "\n";
            pref[i] += (i > 0 ? pref[i-1] : 0) + (s[i]=='0');
            suff[n-i-1] += (i<n-1 ? suff[n-i] : 0) + (s[n-i-1]=='1');
        }
        for(int i=0; i<n-1;i++)
        {
            maxx = max(pref[i]+suff[i+1], maxx);
        }
        return maxx;
    }
};