#define tp tuple<int, int, int>

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid)
    {
        int ans = grid[0][0], n = grid.size();
        int dir[5] = {-1,0,1,0,-1};
        priority_queue<tp, vector<tp>, greater<tp>> pq;
        pq.push({grid[0][0], 0, 0});
        while(!pq.empty())
        {
            auto [u, i, j] = pq.top();
            pq.pop();
            ans = max(ans, u);
            if(i==n-1 && j==n-1)
                return ans;
            if(u == -1)   continue;
            grid[i][j] = -1;
            
            for(int k=0; k<4; k++)
            {
                int nx = i+dir[k], ny = j+dir[k+1];
                if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]!=-1)
                    pq.push({grid[nx][ny], nx, ny});
            }
        }
        return ans;
    }
};

// template<typename T>
// using min_heap = priority_queue<T, vector<T>, greater<T>>;

// class Solution {
// public:
//     const int dx[4] = {+1, 0, -1, 0};
//     const int dy[4] = {0, +1, 0, -1};
//     int ans, n;
//     bool vis[51][51];
//     int swimInWater(vector<vector<int>>& grid)
//     {
//         min_heap<pair<int, pair<int, int>>> pq;
//         n = grid.size();
//         pq.push({grid[0][0], {0,0}});
//         while (pq.size())
//         {
//             int i = pq.top().second.first;
//             int j = pq.top().second.second;
//             int u = pq.top().first;
//             pq.pop();
            
//             ans=max(ans,u);

//             if (i == n - 1 && j == n - 1)
//                 break;

//             if (vis[i][j]) continue;
//             vis[i][j] = true;
            
//             for (int k=0;k<4;k++)
//             {
//                 int r = dx[k]+i;
//                 int c = dy[k]+j;
//                 if (!isValid(r,c) || vis[r][c]) continue;
//                 pq.push({grid[r][c], {r,c}});
//             }
//         }
//         return ans;
//     }
//     bool isValid(int i, int j) {
//         return i >= 0 && j >= 0 && i < n && j < n;
//     }
// };