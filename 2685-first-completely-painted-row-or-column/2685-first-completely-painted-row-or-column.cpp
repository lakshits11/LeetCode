static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, pair<int, int>> u;
        int m = mat.size(), n = mat[0].size();
        vector<int> row(m, 0);
        vector<int> col(n, 0);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                u[mat[i][j]] = {i, j};
            }
        }

        for(int i=0;i<(m*n); i++)
        {
            pair<int, int> cord = u[arr[i]];
            if(++row[cord.first] == n) return i;
            if(++col[cord.second] == m) return i;
        }
        return (m*n)-1;
    }
};