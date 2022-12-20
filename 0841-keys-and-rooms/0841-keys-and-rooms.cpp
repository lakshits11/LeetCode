class Solution
{
    int n;
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        n = rooms.size();
        vector<bool> vis(n, 0);

        queue<int> q;
        q.push(0);
        vis[0] = true;
        int totalVisRooms = 1;

        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                int key = q.front();
                q.pop();
                for (auto &i : rooms[key])
                {
                    if (vis[i])
                        continue;
                    q.push(i);
                    vis[i] = true;
                    totalVisRooms++;
                }
            }
        }

        if(totalVisRooms!=n)
            return false;
        return true;
    }
};