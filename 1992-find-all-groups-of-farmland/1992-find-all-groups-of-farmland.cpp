static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();
class Solution {
private:
    int maxi = 0, maxj=0;
    void dfs(int i, int j, vector<vector<int>> &land)
    {
        if(i<0 || i>=land.size() || j<0 || j>=land[0].size() || land[i][j]==0)
            return;
        
        land[i][j] = 0;
        maxi = max(maxi, i);
        maxj = max(maxj, j);
        dfs(i+1, j, land);
        dfs(i, j+1, land);
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        ios_base::sync_with_stdio(false);
        int m = land.size(), n = land[0].size();
        vector<vector<int>> ans;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(land[i][j]==1)
                {
                    vector<int> temp(4);
                    temp[0]=i, temp[1]=j;
                    maxi = 0, maxj = 0;
                    dfs(i, j, land);
                    temp[2]=maxi, temp[3]=maxj;
                    ans.push_back(temp);
                }
            }
        }
        
        return ans;
        
    }
};