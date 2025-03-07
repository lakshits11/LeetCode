class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        int a=x,b=y,c=x+y;
        int steps[] = {a,-a,b,-b};

        queue<int> q;
        vector<int> vis(c+1, 0);
        q.push(0);
        vis[0]=1;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            if(node == target) return true;

            for(int i=0;i<4;i++)
            {
                int newNode = node + steps[i];
                if(newNode >=0 && newNode <= c && vis[newNode] == 0)
                {
                    q.push(newNode);
                    vis[newNode] = 1;
                }
            }
        }

        return false;
    }
};