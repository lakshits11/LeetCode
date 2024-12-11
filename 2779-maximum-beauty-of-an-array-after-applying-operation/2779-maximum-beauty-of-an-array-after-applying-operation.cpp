static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

// class Solution {
// public:
//     int maximumBeauty(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int> pref(3*100002, 0);
//         for(int i = 0; i < n; ++i)
//         {
//             pref[nums[i]-k+100000]++;
//             pref[nums[i]+k+100001]--;
//         }
//         int maxx = pref[0];
//         for(int i=1;i<pref.size();++i)
//         {
//             pref[i]+=pref[i-1];
//             maxx = max(maxx, pref[i]);
//         }
//         return maxx;
//     }
// };

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        int maxx = 0;
        map<int, int> pref;
        for(int i = 0; i < n; ++i)
        {
            pref[nums[i]-k]++;
            pref[nums[i]+k+1]--;
        }
        int prev = 0;
        for(auto &x : pref)
        {
            prev += x.second;
            maxx = max(maxx, prev);
        }
        return maxx;
    }
};