static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();
class Solution {
public:
    int dir[5] = {-1, 0, 1, 0, -1};
    int m, n;
    int dfs(int i, int j, vector<vector<int>> &g)
    {
        int cnt = g[i][j];
        g[i][j] = 0;
        for(int x=0;x<4;x++)
        {
            int nx = i+dir[x];
            int ny = j+dir[x+1];
            if(nx>=0 && ny>=0 && nx<m && ny<n && g[nx][ny]>0)
                cnt += dfs(nx, ny, g);
        }
        return cnt;
    }
    int findMaxFish(vector<vector<int>>& g) {
        m = g.size(), n = g[0].size();
        int ans = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(g[i][j]>0) {
                    ans = max(ans, dfs(i, j, g));
                }
            }
        }
        return ans;
    }
};