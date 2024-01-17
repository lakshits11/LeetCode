static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int cnt[2001];
        memset(cnt, 0, sizeof(cnt));
        for(int n : arr)
        {
            ++cnt[n+1000];
        }
        unordered_set<int> s;
        int temp = 0;
        for(int i=0;i<2001;++i)
        {
            if(cnt[i]!=0){
                s.insert(cnt[i]);
                temp++;
            }
        }
        return s.size()==temp;
    }
};