class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        ios_base::sync_with_stdio(false);
        queue<int> q;
        int ans = 0;
        bool vis[1001];
        for(int i=0;i<=1000;i++) vis[i]=false;
        q.push(start);
        while(!q.empty())
        {
            int qlen = q.size();
            for(int i = 0; i < qlen; i++)
            {
                int temp = q.front();
                q.pop();
                if(temp == goal)
                    return ans;
                if(temp<0 || temp>1000 || vis[temp])
                    continue;
                vis[temp]=true;
                for(int i = 0; i<nums.size();i++)
                {
                    int a = temp+nums[i], b = temp-nums[i], c = temp^nums[i];
                    q.push(a);q.push(b);q.push(c);
                }
            }
            ans++;
        }
        return -1;
    }
};