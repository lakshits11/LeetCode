static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c=  matrix[0].size();
        vector<vector<int>> ans;
        for(int j=0;j<c;j++)
        {
            vector<int> temp;
            for(int i=0;i<r;i++)
            {
                temp.push_back(matrix[i][j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};