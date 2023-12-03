class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);
        int ans = 0;
        for(int i = 1; i < points.size(); i++) {
            ans += max(abs(points[i][1]-points[i-1][1]), abs(points[i][0]-points[i-1][0]));
        }
        return ans;
    }
};