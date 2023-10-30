class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = rooms.size();
        vector<bool> vis(n, 0);

        queue<int> q;
        q.push(0);
        vis[0] = true;
        int totalVisRooms = 1;

        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; ++i)
            {
                int key = q.front();
                q.pop();
                for (int &i : rooms[key])
                {
                    if (vis[i])
                        continue;
                    q.push(i);
                    vis[i] = true;
                    totalVisRooms++;
                }
            }
        }

        return (totalVisRooms==n);
    }
};