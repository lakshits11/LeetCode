class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& wv, vector<vector<int>>& fr, int id, int ll) {
        queue<int> q;
        q.push(id);
        int level = 0;
        vector<int> vis(wv.size(), 0);
        vis[id] = 1;
        
        while(!q.empty())
        {
            int qlen = q.size();
            if(level == ll)
            {
                unordered_map<string, int> mp;
                vector<pair<int, string>> resPair;
                vector<string> result;
                while(!q.empty())
                {
                    int nd = q.front();
                    q.pop();
                    for(string x : wv[nd])
                    {
                        mp[x]++;
                    }
                }
                for(pair<string, int> x : mp)
                {
                    resPair.push_back({x.second, x.first});
                }
                sort(resPair.begin(), resPair.end());

                transform(resPair.begin(),resPair.end(),back_inserter(result),[](pair<int,string>&p){return p.second;});
                return result;
            }
            while(qlen--)
            {
                int node = q.front();
                q.pop();
                for(int x : fr[node])
                {
                    if(!vis[x])
                    {
                        vis[x] = 1;
                        q.push(x);
                    }
                }
            }
            level++;
        }
        return {};
    }
};