// class Solution {
// public:
//     int maxFrequencyElements(vector<int>& nums) {
        
//     }
// };
static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();
#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freq[101]={0}, maxF=0;
        for (int &x: nums){
            ++freq[x];
            maxF=max(maxF, freq[x]);
        }
        int ans=0;
        for (int f: freq){
            if (f==maxF)
                ans+=f;
        }
        return ans;
    }
};