class Solution {
public:
    string removeDigit(string number, char digit)
    {
        for(int i=0;i<number.size();i++)
        {
            if(number[i]==digit && number[i+1]>digit)
                return number.substr(0,i)+number.substr(i+1);
        }
        
        // if above conditions do not occur, then find the last occurence of number.
        int lst = number.rfind(digit);
        return number.substr(0,lst)+number.substr(lst+1);
    }
};