static const auto speedup = []() -> int{
    std::ios_base::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class Solution {
public:
    int maximumLength(vector<int>& a) {
        int cntE = !(a[0] % 2), cntO = a[0] % 2;
        int cntx = 1;
        int last = a[0] % 2;
        for (int i = 1; i < a.size(); ++i) 
        {
            if (a[i] % 2)
                cntO++;
            else
                cntE++;
            if (a[i] % 2 == !last) 
            {
                last = !last;
                cntx++;
            }
        }
        return max({cntE, cntO, cntx});
    }
};