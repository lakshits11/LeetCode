static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();
class Solution {
public:
    vector<int> finalPrices(vector<int>& p) {
        stack<int> s;
        int x = 0;
        int n = p.size();
        // vector<int> nse(n);
        for(int i=n-1;i>=0;--i)
        {
            while(!s.empty() && s.top()>p[i])
                s.pop();
            int x = (!s.empty()?s.top():0);            
            // nse[i] = !s.empty()?s.top():-1;
            s.push(p[i]);
            p[i] -= x;

        }
        // for(int i=0;i<n;i++)
        // {
        //     if(nse[i]!=-1)
        //         p[i]-=nse[i];
        // }
        return p;
    }
};