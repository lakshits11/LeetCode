class Solution {
private:
    int memo[101][101];
	
    int recursion(const string &s, int i, int K){
        int n = s.length(), k = K;
        // if # of chars left are < k than all can be removed
        // resultant length of string at this stage will be 0
        if(n-i<=k) return 0;
        if(memo[i][k]!=-1) return memo[i][k];
		
		// solving for when ith character is not taken into code
		// when k is non zero else assigning a large number to answer
		// c to count the occurence of the ith element
		// initially set to 1 as the its character is already taken into account
        int ans = k?recursion(s,i+1,k-1):101, c = 1;
		
		// running a loop to group the similar characters
		// notice running the loop upto n because the previous character
		// is added to the resultant encoded code's length after its loop is over
        for(int j=i+1;j<=n;j++){
			// adding previous character to resultant code's length, adding 1, 2 or 3 to take
			// account of the count of current character w.r.t. c and sending the rest of the
			// string for similar evaluation
            ans = min(ans,1+((c>99)?3:(c>9)?2:(c>1)?1:0)+recursion(s,j,k));
			
            if(j<n and s[i]==s[j]) c++;
			// here using else if because we do not need to break if k is negative
			// and s[i] == s[j], because they are similar and might not add to the length
			// of the encoded code length
            else if(--k<0) break;
        }
        return memo[i][K] = ans;
    }
    
public:
    int getLengthOfOptimalCompression(string s, int k) {
        memset(memo,-1,sizeof(memo));
        return recursion(s,0,k);
    }
};