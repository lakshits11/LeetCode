class Solution {
public:
    int countPairs(vector<int>& a) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);
        unordered_map<int, int> u;
        long long ans = 0;
        for(int &x : a)
        {
            for(int i = 1; i <= (1<<22); i*=2)
                if(u.count(i-x))
                    ans += u[i-x];
            u[x]++;
        }
        return ans%(int)(1e9+7);
    }
};