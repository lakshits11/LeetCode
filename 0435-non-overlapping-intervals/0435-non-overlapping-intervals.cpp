class Solution {
public:
    static const bool comp(vector<int> &a, vector<int> &b)
    {
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intr)
    {
        if(intr.size()==0)  return 0;
        sort(intr.begin(), intr.end(), comp);
        int ans = -1;
        vector<int> prev = intr[0];
        for(vector<int> x : intr)
        {
            if(prev[1]>x[0])
                ans++;
            else prev = x;
        }
        return ans;
        
    }
};