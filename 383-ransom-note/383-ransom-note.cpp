class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int mag[26];
        int ran[26];
        memset(mag, 0, sizeof(mag));
        memset(ran, 0, sizeof(ran));
        for(int i=0;i<magazine.size();i++)
            mag[magazine[i]-'a']++;
        for(int i = 0; i < ransomNote.size(); i++)
        {
            if(mag[ransomNote[i]-'a']>0)
                mag[ransomNote[i]-'a']--;
            else return false;
        }
        return true;
    }
};