class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colored(graph.size(), -1);
        colored[0]=1;
        vector<int> visited(graph.size(),0);
        
        for(int i=0;i<graph.size();i++)
        {
            if(visited[i]==0)
            {
                visited[i]=1;
                queue<int> q;
                q.push(i);

                while(!q.empty())
                {
                    int u = q.front();
                    q.pop();

                    for(int x : graph[u])
                    {
                        if(colored[x]==-1)
                        {
                            colored[x]=1-colored[u];
                            q.push(x);
                        }
                        else if(colored[x]==colored[u])
                        {
                            return false;
                        }
                    }
                }
            }
        }
        
        return true;
        
        
    }
};