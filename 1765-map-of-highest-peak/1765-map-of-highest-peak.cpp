static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isw) {
        queue<pair<int, int>> q;
        int m = isw.size(), n = isw[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (isw[i][j] == 1){
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }
        int dir[5] = {-1, 0, 1, 0, -1};
        while(!q.empty())
        {
            pair<int, int> pt = q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                // cout << pt.first << ", " << pt.second << "\n";
                int nx = pt.first + dir[i];
                int ny =  pt.second + dir[i+1];
                if(nx<0 || ny<0 || nx>=m || ny >= n || ans[nx][ny]!=-1)
                    continue;
                // cout << "nx, ny: " << nx << ", " << ny << "\n";
                ans[nx][ny] = ans[pt.first][pt.second] + 1;
                // cout << "ans[nx][ny] = " << ans[nx][ny] << "\n";
                q.push({nx, ny});
            }
        }
        return ans;
    }
};