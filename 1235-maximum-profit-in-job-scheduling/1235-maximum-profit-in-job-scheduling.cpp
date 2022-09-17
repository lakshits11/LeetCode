class Solution {
private:
    int getNext(int end, vector<vector<int>> &v, int idx)
    {
        int lo = idx+1, hi = v.size();
        int ans = -1;
        while(lo < hi)
        {
            int mid = lo + (hi - lo)/2;
            if(v[mid][0] >= end)
            {
                ans = mid;
                hi = mid;
            }
            else lo = mid+1;
        }
        return ans;
    }
    int getMax(vector<vector<int>> &v, vector<int> &dp, int idx)
    {
        if(idx >= v.size() || idx < 0) return 0;
        if(dp[idx] != -1) return dp[idx];
        int dontTake = getMax(v, dp, idx+1);
        int take = v[idx][2] + getMax(v, dp, getNext(v[idx][1], v, idx)); // getNext -> current endtime, vector, current index
        return dp[idx] = max(dontTake, take);
    }
public:
    int jobScheduling(vector<int>& st, vector<int>& en, vector<int>& pr)
    {
        // start, end, profit
        vector<vector<int>> v;
        for(int i = 0; i < st.size(); i++)
        {
            v.push_back({st[i], en[i], pr[i]});
        }
        sort(v.begin(), v.end());
        vector<int> dp(v.size(), -1);
        return getMax(v, dp, 0);
    }
};