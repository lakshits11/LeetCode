class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        ios_base::sync_with_stdio(false);
        int n = graph.size();
        vector<int>color(n,-1);
        
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                // then we have to check there is no matching color
                if(!dfs(i,color,graph)) return false;
            }   
        }
        return true;
    }
    
    bool dfs(int node,vector<int>&color,vector<vector<int>>&graph){
       
        if(color[node]==-1)color[node] =1;
        
        for(auto it:graph[node]){
            if(color[it]==-1){
                color[it] = 1- color[node];
                if(!dfs(it,color,graph))return false;
            }
            if(color[it]==color[node]) return false;
            
        }
        return true;
    }
};