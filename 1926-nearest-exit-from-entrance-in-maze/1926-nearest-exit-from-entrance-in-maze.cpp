class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& ent) {
        queue<pair<int, int>> q;
        q.push({ent[0], ent[1]});
        maze[ent[0]][ent[1]] = '+';
        const int dir[5] = {-1,0,1,0,-1};
        int res = 1, rows = maze.size(), cols = maze[0].size();
        while(!q.empty())
        {
            int qlen = q.size();
            while(qlen--)
            {
                int a = q.front().first, b = q.front().second;
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int x = a+dir[i], y = b+dir[i+1];
                    if(x<0 || y<0 || x>=rows || y>=cols || maze[x][y]=='+')   continue;
                    if(x==0 || y==0 || x==rows-1 || y==cols-1)
                        return res;
                    maze[x][y]='+';
                    q.push({x,y});
                }
            }
            res++;
        }
        return -1;
        
    }
};