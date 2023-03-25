class Solution {
private:
    vector<int> arr;
public:
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(false);
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        int vis[n];int temp;
        memset(vis, 0, sizeof(vis));
        for(int i=0;i<n;i++)
        {
            if(vis[i])
                continue;
            queue<int> q;
            temp = 1;
            q.push(i);
            vis[i] = 1;
            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                for(int x : adj[node])
                {
                    if(vis[x]==0) {
                        vis[x] = 1;
                        temp++;
                        q.push(x);
                    }
                }
            }
            arr.push_back(temp);
        }
        // int arr[s.size()];
        // for(int i=0;i<s.size();i++)
        // {
        //     arr[i] = s[i].size();
        //     cout << arr[i] << " ";
        // }
        unsigned long long ans = 0;
        // for(int i=0;i<arr.size()-1;i++)
        // {
        //     for(int j=i+1;j<arr.size();j++)
        //     {
        //         ans += (arr[i]*arr[j]);
        //     }
        // }
        for(int i=0;i<arr.size();i++)
        {
            long long a = n-arr[i];
            ans += (a*arr[i]);
            cout << ans << "\n";
            n -= arr[i];
        } 
        
        // for(int i=0;i<arr.size();i++)
        // {
        //     cout << arr[i] << " ";
        // }
        // cout << "\n";
        
        return ans;
        
    }
};