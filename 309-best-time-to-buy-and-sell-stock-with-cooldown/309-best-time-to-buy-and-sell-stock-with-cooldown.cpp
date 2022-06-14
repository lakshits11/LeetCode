class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int curr[2], fut1[2], fut2[2];
        memset(curr, 0, sizeof(curr));
        memset(fut1, 0, sizeof(fut1));
        memset(fut2, 0, sizeof(fut2));
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<2;++j)
            {
                if(j==0)
                    curr[0] = max(fut1[0], -prices[i]+fut1[1]);
                else
                    curr[1] = max(fut1[1], prices[i]+fut2[0]);
            }
            /* fut2=fut1
            fut1=curr
            */
            copy(fut1, fut1+2, fut2);
            copy(curr, curr+2, fut1);
        }
        return curr[0];
    }
};