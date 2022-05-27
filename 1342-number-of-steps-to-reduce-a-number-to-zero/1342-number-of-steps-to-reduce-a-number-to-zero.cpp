class Solution {
public:
    int numberOfSteps(int num) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int ans = 0;
        while(num>0)
        {
            if(num%2==0)
            {
                ans++;
                num/=2;
            }
            else{
                ans++;
                num--;
            }
        }
        return ans;
    }
};