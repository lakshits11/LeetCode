class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int rows = matrix.size(), cols = matrix[0].size();
        int l = 0, r = rows*cols - 1;
        while(l <= r)
        {
            int mid = (l+r) >> 1;
            if(matrix[mid/cols][mid%cols] == target)
                return true;
            if(matrix[mid/cols][mid%cols] < target)
                l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};