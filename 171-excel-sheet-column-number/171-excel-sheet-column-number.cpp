class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.length();
        int mul = 0;
        int ans=0;
        for(int i=n-1;i>=0;i--)
        {
            int x = columnTitle[i]-'A'+1;
            ans += x * pow(26, mul);
            mul++;
        }
        return ans;
    }
};