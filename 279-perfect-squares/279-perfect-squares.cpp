class Solution {
public:
    int numSquares(int n) {
        if(n <= 0)
            return 0;
        static vector<int> cnt({0});
        while(cnt.size() <= n)
        {
            int m = cnt.size();
            int cntOfSquares = INT_MAX;
            for(int i = 1; i*i <= m; i++)
            {
                cntOfSquares= min(cntOfSquares, cnt[m - i*i] + 1);
            }
            cnt.push_back(cntOfSquares);
        }
        return cnt[n];
    }
};