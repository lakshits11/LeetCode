class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        
        return (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) ? edges[0][0] : edges[0][1];
    }
};