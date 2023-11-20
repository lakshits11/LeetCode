class Solution {
public:
    int garbageCollection(vector<string>& g, vector<int>& travel) {
        int ans = 0;
        for(char c: {'G','M','P'}){
            int res = 0, lastpick = 0;
            for(int i = 0; i < g.size(); i++){
                int cnt = count(g[i].begin(), g[i].end(), c);
                if(cnt > 0){
                    res += cnt;
                    lastpick = i;
                }
                if(i < travel.size()) res += travel[i];
            }
            for(int i = g.size() - 2; i >= lastpick; i--){
                res -= travel[i];
            }
            ans += res;
        }
        return ans;
    }
};