class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        if(x==1)
            return 1;
        if(x==-1)
        {
            if(n%2==0)
                return 1;
            return -1;
        }
        
        if(n<0)
        {
            long t = -1;
            t *= n;
            while(t--)
            {
                ans /= x;
                if(ans == 0) return ans;
            }
            
            return ans;
        }
        while(n--){
            ans *= x;
            if(ans == 0)    return ans;
        }
        return ans;
        
    }
};