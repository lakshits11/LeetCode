class Solution {
public:
    // bool isLongPressedName(string name, string typed) {
    //     int i=0,j=0;
    //     while(i<name.length() && j<typed.length())
    //     {
    //         if(typed[j]==name[i])
    //         {
    //             i++;
    //             j++;
    //         }
    //         else if(typed[j]==typed[j+1])
    //             j++;
    //         else if(i==name.length()-1 && typed[j]!=typed[j+1])
    //             return false;
    //     }
    //     if(i<name.length())
    //         return false;
    //     return true;
    // }
    bool isLongPressedName(string name, string typed) {
        int i=0,j=0;
        int m = name.length(), n = typed.length();
        while(j<n)
        {
            if(i<m && name[i]==typed[j])
            {   
                i++;
                j++;
            }
            else if(i>0 && name[i-1]==typed[j])
                j++;
            else
                return false;
        }
        return i==m;
    }
};