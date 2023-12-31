class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> arr[26];
        for(int i=0;i<26;i++)
            arr[i]={};
        for(int i=0; i<s.size(); ++i)
            arr[s[i]-'a'].push_back(i);
        int mini = -1;
        for(int i=0;i<26;i++)
        {
            for(int x=1;x<arr[i].size();++x)
                mini = max(mini, arr[i][x]-arr[i][0]-1);
        }
        return mini;
    }
};