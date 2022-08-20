class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int stationIndex = 0, fuelStock = 0;
        int n = stations.size();
        priority_queue<int> pq;
        pq.push(startFuel);
        for(int stationCount = 0; !pq.empty(); stationCount++)
        {
            int curr = pq.top();
            pq.pop();
            fuelStock += curr;
            if(fuelStock >= target)
                return stationCount;
            // pushing all the stations where we can reach
            // and from these we will choose station with maximum fuel
            while(stationIndex < n && stations[stationIndex][0] <= fuelStock){
                pq.push(stations[stationIndex++][1]);
            }
        }
        return -1;
    }
};