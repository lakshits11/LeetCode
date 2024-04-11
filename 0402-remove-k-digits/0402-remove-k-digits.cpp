static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class Solution {
public:
    string removeKdigits(string nums, int k)
    {
        string s;
        for(int i=0;i<nums.size();i++)
        {
            while(!s.empty() && s.back()>nums[i] && k>0)
            {
                k--;
                s.pop_back();
            }
            s.push_back(nums[i]);
        }
        while(k>0)
        {
            k--;
            s.pop_back();
        }
        int i=0;
        while(s[i]=='0')
            i++;
        if(i==s.size())
            return "0";
        return s.substr(i);
        
    }
};