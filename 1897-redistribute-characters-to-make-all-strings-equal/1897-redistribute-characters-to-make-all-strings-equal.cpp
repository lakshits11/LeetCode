class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int arr[26];
        int n = words.size();
        memset(arr, 0, sizeof(arr));
        for(string &s : words)
        {
            for(char &c:s){
                arr[c-'a']++;
            }
        }
        for(int i=0;i<26;i++)
        {
            if(arr[i]%n!=0) return false;
        }
        return true;
    }
};