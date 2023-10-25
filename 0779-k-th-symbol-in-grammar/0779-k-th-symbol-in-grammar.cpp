class Solution {
public:
    int kthGrammar(int N, int K) {
        // base case
        if(N==1) {
            return 0;
        }

        if(K%2==1) {
            return kthGrammar(N-1, (K+1)/2);
        } else {
            return !(kthGrammar(N-1, K/2));
        }
    }
};