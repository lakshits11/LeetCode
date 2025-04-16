class Solution {
public:
    int mod = 1e9+7;

    long long power(long long x, long long y)
    {
        long long res = 1;
        x %= mod;
        if(x == 0) return 0;

        while(y > 0)
        {
            // if y is odd, multiply x with result
            if(y&1) res = (res*x)%mod;

            // now for remaining, make the even setup
            y = y >> 1;
            x = (x*x) % mod;
        } 
        return res;
    }

    int countGoodNumbers(long long n) {
        long long count_of_4 = n/2;
        long long count_of_5 = n - count_of_4;
        long long ans = ((power(4LL, count_of_4) % mod * power(5LL, count_of_5) % mod) % mod);
        return ans;
    }
};
