class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        if(accumulate(gas.begin(), gas.end(),0) < accumulate(cost.begin(),cost.end(),0))
            return -1;
        int start = 0, total = 0;
        for(int i=0;i<gas.size();i++)
        {
            total += gas[i]-cost[i];
            if(total < 0) {
                total = 0;
                start = i+1;
            }
        }
        return start;
        
    }
};