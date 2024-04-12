static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();
class Solution {
public:
    int trap(vector<int>& ht) {
        int n = ht.size();
        int l = 0, r = n-1, ml = 0, mr = 0;
        int ans = 0;
        while(l <= r)
        {
            if(ht[l] <= ht[r])
            {
                if(ml < ht[l])
                    ml = ht[l];
                else ans += ml-ht[l];
                l++;
            }
            else {
                if(mr < ht[r]) mr = ht[r];
                else ans += mr-ht[r];
                r--;
            }
        }
        return ans;
    }
};