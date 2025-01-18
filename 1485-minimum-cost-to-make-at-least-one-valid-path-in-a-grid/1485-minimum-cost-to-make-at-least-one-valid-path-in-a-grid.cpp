// static const auto speedup = []() -> int {
//    std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return 0;
// }();
// class Solution
// {
// public:
//     int minCost(vector<vector<int>> &grid)
//     {
//         int m = grid.size(), n = grid[0].size();
//         deque<pair<int, int>> q{{0, 0}};
//         int dir[5] = {-1, 0, 1, 0, -1};
//         unordered_set<int> vis;

//         int res = 0;
//         while (!q.empty())
//         {
//             pair<int, int> t = q.front();
//             q.pop_front();

//             int curi = t.first / n, curj = t.first % n;
//             if (vis.insert(t.first).second) // that means element does not already exists in set
//                 res = t.second;
//             else continue;


//             // read return values of insert function in set for more clarity

//             if (curi == m - 1 && curj == n - 1)
//                 return res;

//             for (int i = 0; i < 4; i++)
//             {
//                 int x = curi + dir[i], y = curj + dir[i + 1];
//                 int pos = x * n + y;
//                 if (x < 0 || y < 0 || x >= m || y >= n || vis.count(pos))
//                     continue;

//                 int cost;
//                 // basically i ki value isiye check kr rhe for direction
//                 // if grid and direction array point to same direction, then cost 0
//                 // else cost to go to that direction = 1
//                 // i == 1 means directio point to dir[i], dir[i+1] i.e. (0, 1) i.e. up direction
//                 if (grid[curi][curj] == 1 && i == 1)
//                     cost = 0;
//                 else if (grid[curi][curj] == 2 && i == 3)
//                     cost = 0;
//                 else if (grid[curi][curj] == 3 && i == 2)
//                     cost = 0;
//                 else if (grid[curi][curj] == 4 && i == 0)
//                     cost = 0;
//                 else
//                     cost = 1;

//                 if (cost == 1)
//                     q.push_back({pos, t.second + cost});
//                 else
//                     q.push_front({pos, t.second + cost});
//             }
//         }
//         return res;
//     }
// };

// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/solutions/524936/c-0-1-bfs-o-n-instead-of-o-nlogn

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};

        int dist[n][m];

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dist[i][j]=INT_MAX;
            }
        }
        deque<pair<int,int>>dq;
        dq.push_back({0,0});
        dist[0][0]=0;

        while(dq.size()>0){
            auto curr=dq.front();
            dq.pop_front();
            int x=curr.first;
            int y=curr.second;
            int dir=grid[x][y];

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                int edgewt=1;
                if(i+1==dir) edgewt=0;

                if(nx<n and ny<m and nx>=0 and ny>=0){
                    if(dist[nx][ny]>dist[x][y]+edgewt){
                        dist[nx][ny]=dist[x][y]+edgewt;
                        if(edgewt==1){
                            dq.push_back({nx,ny});
                        }else{
                            dq.push_front({nx,ny});
                        }
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};