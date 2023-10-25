class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int ind[n+1];
        int outd[n+1];
        for(int i=0;i<n+1;i++)
        {
            ind[i]=0;outd[i]=0;
        }
        for(int i=0;i<trust.size();++i){
            outd[trust[i][0]]++;
            ind[trust[i][1]]++;
        }
        for(int i=1;i<n+1;i++)
        {
            if(outd[i]==0 && ind[i]==n-1)
                return i;
        }
        return -1;
    }
};