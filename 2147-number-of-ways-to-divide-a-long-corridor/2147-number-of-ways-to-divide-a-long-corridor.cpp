class Solution {
public:
    int mod = 1e9+7;
    int numberOfWays(string corr) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);
        vector<int> pos;
        for(int i=0;i<corr.size();i++)
        {
            if(corr[i]=='S')
                pos.push_back(i);
        }
        if(pos.size()%2 || pos.size()==0) return 0;
        
        long long ans = 1;
        int prev = pos[1];
        for(int i=2;i<pos.size();i+=2)
        {
            int pp = pos[i]-prev;
            ans = (ans*pp)%mod;
            prev = pos[i+1];
        }
        return ans;
    }
};