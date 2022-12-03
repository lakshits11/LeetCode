class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> u;
        for(int i : nums)
            u[i]++;
        sort(begin(nums), end(nums), 
            [&](int a, int b){
                return u[a]==u[b] ? a > b : u[a] < u[b];
        });
        return nums;
    }
};