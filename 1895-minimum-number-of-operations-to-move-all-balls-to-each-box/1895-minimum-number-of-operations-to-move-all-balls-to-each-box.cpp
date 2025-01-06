class Solution {
public:
    vector<int> minOperations(string bx) {
        int n = bx.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        vector<int> ans;

        int cnt = bx[0]-'0';
        for(int i=1;i<n;i++)
        {
            left[i] = left[i-1] + cnt;
            cnt += bx[i]-'0';
        }
        cnt = bx[n-1]-'0';
        for(int i=n-2;i>=0;i--)
        {
            right[i]=right[i+1]+cnt;
            cnt += bx[i]-'0';
        }
        for(int i=0;i<n;i++)
        {
            ans.push_back(left[i]+right[i]);
        }
        return ans;
    }
};