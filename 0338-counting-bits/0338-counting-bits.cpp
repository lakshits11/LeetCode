class Solution {
public:
    vector<int> countBits(int n) {
        ios_base::sync_with_stdio(false);
        vector<int> ans(n+1,0);
        for(int i=1;i<=n;i++)
        {
            if(i%2==0)
                ans[i] = ans[i/2];
            else
                ans[i] = ans[i/2] + 1;
        }
        return ans;
    }
};