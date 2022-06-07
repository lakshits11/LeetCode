class Solution {
public:
    
    // must see discussions:
    // https://leetcode.com/problems/unique-paths/discuss/22954/C%2B%2B-DP
    // https://leetcode.com/problems/unique-paths/discuss/22958/Math-solution-O(1)-space
    
    int uniquePaths(int m, int n) {
        int curr[n];
        for(int i=0;i<n;i++)    curr[i]=1;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++)
            {
                curr[j] += curr[j-1];
            }
        }
        return curr[n-1];
                
    }
};
