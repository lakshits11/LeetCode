class Solution {
public:
    bool ispalin(string &s, int i, int j)
    {
        while(i<=j)
        {
            if(s[i]!=s[j])  return false;
            i++;
            j--;
        }
        return true;
    }
    
    bool checkPalindromeFormation(string a, string b) {
        int i=0, j=b.size()-1;
        while(a[i]==b[j])
        {
            i++;
            j--;
            if(i>j)
                return true;
        }
        if(ispalin(a,i,j) || ispalin(b,i,j))  return true;
        
        i=0,j=a.size()-1;
        while(b[i]==a[j])
        {
            i++;
            j--;
            if(i>j) return true;
        }
        return ispalin(b,i,j) || ispalin(a,i,j);
    }
};