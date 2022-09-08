class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long total = 0;
        for(int i=0;i<piles.size();i++)
            total += piles[i];
        long long int l = 1;
        long long int r = total;
        
        while(l < r)
        {
            long long mid = l + (r-l)/2;
            long long hrCount = 0;
            // cout << mid << ": ";
            for(int i = 0; i < piles.size(); i++)
            {
                double x = ceil ((double)piles[i] / (double)mid);
                // cout << x << " ";
                hrCount += (long long)x;
            }
            // cout << "\n";
            if (hrCount > h)
                l = mid+1;
            else r = mid;
        }
        return l;
    }
};