class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& e) {
        vector<int> ind(n), ans;
        for(auto &edge : e)
        {
            ind[edge[1]]++;
        }
        for(int i=0;i<n;i++){
            if(ind[i]==0)
                ans.push_back(i);
        }
        return ans;
    }
};