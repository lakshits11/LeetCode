static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) 
    {
        int n = arr.size();
        int up = 1, down = 1, ans = 1;
        for (int i = 1; i < n; ++i) 
        {
            if (arr[i] > arr[i - 1]) 
            {
                up = down + 1;
                down = 1;
            } 
            else if (arr[i] < arr[i - 1]) 
            {
                down = up + 1;
                up = 1;
            } 
            else 
            {
                up = down = 1;
            }
            ans = max(ans, max(up, down));
        }
        return ans;
    }
};