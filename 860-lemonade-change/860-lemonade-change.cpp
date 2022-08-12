class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int nf = 0, nt = 0, ntw = 0;
        for(int i = 0 ; i < bills.size(); i++)
        {
            if(bills[i] == 5)
            {
                nf++;
            }
            else if(bills[i]==10)
            {
                nt++;
                if(nf>0)
                    nf--;
                else return false;
            }
            else
            {
                ntw++;
                if(nf>0 && nt>0)
                    nf--,nt--;
                else if(nf>=3)
                    nf-=3;
                else return false;
            }
        }
        return true;
    }
};