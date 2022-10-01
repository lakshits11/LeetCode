class Solution {
private:
    void setup_LPS(vector<int> &lps, string &needle)
    {
        // for example (heloshel): hel | os | hel
        //                         *** | -- | ***
        // hel is longest prefix suffix
        // prevLPS: prev index where we had LPS
        // i: current character we are looking at
        int prevLPS = 0, i = 1;
        while(i < needle.size())
        {
            if(needle[i] == needle[prevLPS])
            {
                lps[i] = prevLPS + 1;
                prevLPS++;
                i++;
            }
            else
            {
                // take case like "AB"
                // LPS=[0, *]
                // for star position, needle[i] != needle[prevLPS] and also prevLPS == 0, so here we see that lps[i] should be 0
                if(prevLPS == 0)
                {
                    lps[i] = 0;
                    i++;
                }
                else
                {
                    prevLPS = lps[prevLPS - 1];
                }
            }
        }
    }
public:
    int strStr(string haystack, string needle) {
        if(needle == "") return 0;
        
        // firstly we need to set up lps array
        // Longest Prefix Suffix: Longest length of a string which is same from front and back
        vector<int> lps(needle.size(), 0);
        setup_LPS(lps, needle);
        
        // KMP Part
        int i = 0, j = 0; // i for haystack, j for needle
        while(i < haystack.size())
        {
            if(haystack[i] == needle[j])
                i++, j++;
            else
            {
                // suppose example:
                // haystack : A A A X A A A X
                // needle :   A A A A
                // we see that at index 3, it do not match, so we are gonna check for value of lps for the last matching index (j-1)
                // j-1 ka concept aise samjho: abhi tk sab equal chal rha tha to if loop m hi chal rhe the, abhi equal nhi aaya isliye else loop m aaye matlab j-1 tk to matching tha
                
                if(j == 0)
                    i++;
                else
                    j = lps[j - 1];                
            }
            if(j == needle.size())
                return i - needle.size();
        }
        
        return -1;
    }
};