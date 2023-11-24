class Solution {
public:
    int maxCoins(vector<int>& piles) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        sort(piles.begin(), piles.end());
        int ans =  0, n = piles.size();
        for(int i=n/3;i<n;i+=2)
        {
            ans += piles[i];
        }
        return ans;
    }
};