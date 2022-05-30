class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==1)
            return INT_MIN;
    bool isNegative = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0) ? true : false;
    long absDividend = abs((long) dividend);
    long absDivisor = abs((long) divisor);
    long result = 0;
    while(absDividend >= absDivisor){
        long tmp = absDivisor, count = 1;
        while(tmp <= absDividend){
            tmp <<= 1;
            count <<= 1;
        }
        result += count >> 1;
        absDividend -= tmp >> 1;
    }
    return  isNegative ? (int) ~result + 1 : result > INT_MAX ? INT_MAX : (int) result;
}
};