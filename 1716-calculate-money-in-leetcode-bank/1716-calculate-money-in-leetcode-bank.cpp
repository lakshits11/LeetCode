class Solution {
public:
    int totalMoney(int n) {
        int comp = n/7;
        int partial = n%7;
        int ans = 0, tmp = 28;
        int tmp2 = 1;
        // for(int i=0;i<comp;i++)
        // {
        //     ans += temp;
        //     temp+=7;
        // }
        for(int i=1;i<=n;i++)
        {
            if(i%7==1){
                tmp = (i/7)+1;
            }
            ans += tmp;
            tmp++;
        }
        return ans;
    }
};