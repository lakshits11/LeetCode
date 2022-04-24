class Solution {
public:
    bool isPalindrome(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = s.length();
        int i=0, j=n-1;
        while(i<=j)
        {
            char x = tolower(s[i]);
            char y = tolower(s[j]);
            if(isalnum(x) && isalnum(y)){
                if(x==y){
                    i++;j--;
                }
                else{
                    return false;
                }
            }
            if(!isalnum(x)) i++;
            if(!isalnum(y)) j--;
        }
        return true;
    }
};