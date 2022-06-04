class Solution {
public:
    int minSwaps(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(nullptr);
        // st => stack size
        int st = 0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='[')
                st++;
            else
            {
                if(st>0)
                    st--;
            }
        }
        return (st+1)/2;
        
    }
};