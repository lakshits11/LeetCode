class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> counts;
        int ans = 0;
        
        for (int num: nums) {
            ans += counts[num];
            counts[num]++;
        }
        
        return ans;
    }
};