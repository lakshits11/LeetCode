class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ct = accumulate(cost.begin(), cost.end(), 0);
        int gt = accumulate(gas.begin(), gas.end(), 0);
        if(ct > gt)
            return -1;
        int total = 0, ind = 0;
        for(int i = 0; i < cost.size(); i++)
        {
            total += (gas[i]-cost[i]);
            if(total < 0)
            {
                total = 0;
                ind = i+1;
            }
        }
        return ind;
    }
};