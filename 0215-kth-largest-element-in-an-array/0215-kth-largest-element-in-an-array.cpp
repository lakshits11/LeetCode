class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        priority_queue<int, vector<int>> pq(nums.begin(), nums.end());
        if(nums.size()<k)
            return -1;
        while(--k)
            pq.pop();
        return pq.top();
        
    }
};