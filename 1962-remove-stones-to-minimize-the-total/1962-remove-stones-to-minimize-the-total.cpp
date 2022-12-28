class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end());
        ios_base::sync_with_stdio(0);
        cin.tie(nullptr);
        int ans = 0;
        int n = piles.size();
        while(k--)
        {
            int temp = pq.top();
            pq.pop();
            if(temp%2==0)
                pq.push(temp/2);
            else
                pq.push(floor(temp/2)+1);
        }
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};