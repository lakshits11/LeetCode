class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity)
    {
        int temp[1201] = {};
        
        for(vector<int> &x : trips)
        {
            temp[x[1]] += x[0];
            temp[x[2]] -= x[0];
        }
        if(temp[0]>capacity)
            return false;
        for(int i=1;i<1201;i++)
        {
            temp[i] += temp[i-1];
            if(temp[i] > capacity)
                return false;
        }
        return true;
        
    }
};