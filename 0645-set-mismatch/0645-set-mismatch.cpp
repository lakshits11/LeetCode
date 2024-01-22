static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int dup = 0, miss = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            int x = abs(nums[i]);
            if(nums[x-1]<0 && dup==0)
                dup=x;
            else nums[x-1]*=-1;
        }
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]>=0)
            {
                miss = i+1;
                break;
            }
        }
        return {dup, miss};
    }
};