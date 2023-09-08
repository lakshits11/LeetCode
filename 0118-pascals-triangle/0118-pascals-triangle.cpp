class Solution {
public:
    vector<vector<int>> generate(int n) {
        ios_base::sync_with_stdio(false);
        vector<vector<int>> ans;
        ans.push_back({1});
        if(n==1)    return ans;
        if(n>=2)
        {
            ans.push_back({1,1});
        }
        for(int i=2;i<n;i++)
        {
            vector<int> temp;
            temp.push_back(1);
            for(int j=1;j<i;j++)
                temp.push_back(ans[i-1][j-1]+ans[i-1][j]);
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};