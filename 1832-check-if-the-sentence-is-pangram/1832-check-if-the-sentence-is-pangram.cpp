class Solution {
public:
    bool checkIfPangram(string s) {
        vector<int> arr(26, 0);
        for(char c : s)
        {
            arr[c-'a']++;
        }
        for(int i = 0; i < 26; i++)
        {
            if(arr[i]==0) return false;
        }
        return true;
    }
};