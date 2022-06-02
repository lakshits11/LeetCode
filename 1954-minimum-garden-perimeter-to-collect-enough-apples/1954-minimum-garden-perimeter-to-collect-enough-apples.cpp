class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        ios_base::sync_with_stdio(0);
        long long n=1, s=0, count=0;
        while(neededApples > 0)
        {
            n+=1;
            neededApples -= (12*(n-1)*(n-1));
            count+=2;
        }
        return 4*count;
    }
};