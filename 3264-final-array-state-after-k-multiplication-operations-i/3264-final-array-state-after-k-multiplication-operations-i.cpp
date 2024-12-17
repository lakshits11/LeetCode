static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int mul) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i=0;i<nums.size();++i)
            pq.push({nums[i], i});
        while(k--)
        {
            int elem = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            pq.push({elem*mul, idx});
        }
        for(int i=0;i<nums.size();i++){
            int elem = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            nums[idx] = elem;
        }
        return nums;
    }
};