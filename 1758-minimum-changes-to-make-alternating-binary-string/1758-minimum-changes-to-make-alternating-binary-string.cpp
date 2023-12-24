class Solution {
public:
    int minOperations(string t) {
        int n = t.size();
        int count=0, cnt=0;
        char st = t[0];
        for(int i=0;i<n;i++)
        {
            if(t[i]!=st) count++;
            st=1-(st-'0')+'0';
        }
        st=1-(t[0]-'0')+'0';
        for(int i=0;i<n;i++)
        {
            if(t[i]!=st) cnt++;
            st=1-(st-'0')+'0';
        }
        return min(count, cnt);
    }
};