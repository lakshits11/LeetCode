class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        ios_base::sync_with_stdio(false);
        int n = s.size();
        int lt=0, rt = n-1, ans = 0;
        while(lt < rt)
        {
            int l = lt, r = rt;
            while(s[l]!=s[r])
                r--;
            
            if(l==r)
            {
                swap(s[r], s[r+1]);
                ans++;
                continue;
            }
            else {
                while(r<rt){
                    swap(s[r], s[r+1]);
                    r++;
                    ans++;
                }
            }
            lt++;rt--;
        }
        return ans;
    }
};