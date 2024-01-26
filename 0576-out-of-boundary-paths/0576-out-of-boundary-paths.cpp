class Solution {
public:
    int m, n;
    int memo[50][50][51];
    int dir[5] = {0, 1, 0, -1, 0};
    
    int findPaths(int m, int n, int maxMove, int sr, int sc) {
        this->m = m;
        this->n = n;
        memset(memo, -1, sizeof(memo));
        return dp(sr, sc, maxMove);
    }
    
    int dp(int r, int c, int maxMove)
    {
        if(r<0 || r==m || c<0 || c==n) return 1;
        if(maxMove == 0) return 0;
        if(memo[r][c][maxMove] != -1) return memo[r][c][maxMove];
        int temp = 0;
        for(int k=0;k<4;k++)
            temp = (temp + dp(r+dir[k], c+dir[k+1], maxMove - 1)) % 1000000007;
        return memo[r][c][maxMove] = temp;
    }
};
    
    
    
    
    
    
    
    
    