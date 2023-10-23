class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        while(n!=1)
        {
            if(n%4==0) n=n/4;
            else return false;
        }
        return true;
    }
};