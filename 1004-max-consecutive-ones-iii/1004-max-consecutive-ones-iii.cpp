static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0, r=0, cnt = 0;
        int len=-1;
        for(r=0;r<nums.size();r++){
            if(nums[r]==0) cnt++;
            while(cnt>k)
            {
                if(nums[l]==0) cnt--;
                l++;
            }
            len=max(len, r - l + 1);
        }
        return len;
    }
};