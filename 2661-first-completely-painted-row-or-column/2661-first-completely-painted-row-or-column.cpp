static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> rowSum(m, 0);
        vector<int> colSum(n, 0);
        vector<pair<int, int>> v(100001); // to map elements positions
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                v[mat[i][j]] = {i, j};
            }
        }
        for(int x = 0; x < arr.size(); x++)
        {
            int elX = v[arr[x]].first;
            int elY = v[arr[x]].second;
            if(++rowSum[elX] == n) return x;
            if(++colSum[elY] == m) return x;
        }
        return -1;
    }
};