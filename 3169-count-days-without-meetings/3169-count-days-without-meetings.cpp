class Solution {
public:
    int countDays(int days, vector<vector<int>>& mt) {
        sort(mt.begin(), mt.end());
        vector<vector<int>> mgdMt;
        mgdMt.push_back(mt[0]);
        for(int i=1;i<mt.size();i++)
        {
            if(mt[i][0] <= mt[i-1][1])
            {
                mgdMt.back()[1] = max(mgdMt.back()[1], mt[i][1]);
            }
            else mgdMt.push_back(mt[i]);
        }
        for(vector<int> &x : mgdMt)
        {
            days -= (x[1]-x[0]+1);
        }
        return days;
    }
};