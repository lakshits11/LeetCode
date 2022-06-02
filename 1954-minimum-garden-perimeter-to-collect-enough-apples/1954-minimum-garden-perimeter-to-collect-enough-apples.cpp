class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long n=1, s=0, count=0;
        while(s < neededApples)
        {
            n+=1;
            s += (12*(n-1)*(n-1));
            count+=2;
        }
        return 4*count;
    }
};