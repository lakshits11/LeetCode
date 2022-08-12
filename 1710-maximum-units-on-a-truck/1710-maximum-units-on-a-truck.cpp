bool comp(vector<int> &a, vector<int> &b)
{
    return a[1] > b[1];
}

class Solution {
public:
    int maximumUnits(vector<vector<int>>& bt, int ts) {
        
        int ans = 0;
        sort(bt.begin(), bt.end(), comp);
        for(int i = 0; i < bt.size(); i++)
        {
            if(bt[i][0] < ts)
            {
                ans += (bt[i][0] * bt[i][1]);
                ts -= bt[i][0];
            }
            else
            {
                ans += ts*bt[i][1];
                return ans;
            }
        }
        return ans;
    }
};