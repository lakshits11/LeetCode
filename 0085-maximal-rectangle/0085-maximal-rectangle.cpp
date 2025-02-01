static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();
class Solution {
public:
    int largestRectangleArea(vector<int>& ht) {
        int n = ht.size();
        if (n == 1)
            return ht[0];
        stack<pair<int, int>> s;
        vector<int> nle(n, n);
        vector<int> ple(n, -1);
        s.push({ht[n - 1], n - 1});
        for (int i = n - 2; i >= 0; i--) {
            while (!s.empty() && s.top().first >= ht[i])
                s.pop();
            if (!s.empty())
                nle[i] = s.top().second;
            else
                nle[i] = n;
            s.push({ht[i], i});
        }

        while (!s.empty())
            s.pop();

        s.push({ht[0], 0});
        for (int i = 1; i < n; i++) {
            while (!s.empty() && s.top().first >= ht[i])
                s.pop();
            if (!s.empty())
                ple[i] = s.top().second;
            else
                ple[i] = -1;
            s.push({ht[i], i});
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, (nle[i] - ple[i] - 1) * ht[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& mtx) {
        int m = mtx.size(), n = mtx[0].size();
        vector<vector<int>> mat(m, vector<int>(n, 0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0)
                    mat[i][j] = mtx[i][j]-'0';
                else 
                {
                    if(mtx[i][j]-'0' == 0) mat[i][j] = 0;
                    else mat[i][j] = 1 + mat[i-1][j];
                }
            }
        }
        int ans = 0;
        for(int i=0;i<m;i++)
        {
            ans = max(ans, largestRectangleArea(mat[i]));
        }
        return ans;
    }
};