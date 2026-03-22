class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        
        // Assume all 4 rotations are valid until proven otherwise
        bool c0 = true, c90 = true, c180 = true, c270 = true;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                
                // 0 degrees (No rotation)
                if (mat[i][j] != target[i][j]) 
                    c0 = false;
                
                // 90 degrees clockwise
                if (mat[i][j] != target[j][n - 1 - i]) 
                    c90 = false;
                
                // 180 degrees
                if (mat[i][j] != target[n - 1 - i][n - 1 - j]) 
                    c180 = false;
                
                // 270 degrees
                if (mat[i][j] != target[n - 1 - j][i]) 
                    c270 = false;
                
                // Early Optimization: If all flags are false, stop checking immediately!
                if (!c0 && !c90 && !c180 && !c270) 
                    return false;
            }
        }
        
        // If any of the rotations remained true throughout the whole matrix, it's a match.
        return c0 || c90 || c180 || c270;
    }
};