static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();
class Solution {
public:
    vector<int> finalPrices(vector<int>& p) {
        for(int i=0;i<p.size();++i)
        {
            int j=i+1;
            while(j<p.size() && p[i]<p[j])
                j++;
            if(i!=j && j<p.size())
                p[i] -= p[j];
        }
        return p;
    }
};