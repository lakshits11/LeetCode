class Solution {
public:
    bool can_repair_all(long long &time, vector<int> &ranks, int &cars)
    {
        long long cnt = 0;
        for(int &rank : ranks)
        {
            cnt += floor(sqrt(time/rank));
            if(cnt >= cars) return true;
        }
        return false;
    }

    long long repairCars(vector<int>& ranks, int &cars) {
        long long left = 1, right = (long long)*min_element(ranks.begin(), ranks.end())*cars*cars;

        while(left < right)
        {
            long long mid = left + (right-left)/2;
            if(can_repair_all(mid, ranks, cars)) right = mid;
            else left = mid + 1;
        }

        return left;
    }
};