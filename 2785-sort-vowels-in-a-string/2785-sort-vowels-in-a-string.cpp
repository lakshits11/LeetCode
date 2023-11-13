class Solution {
public:
    bool isvowel(char v) {
        return (0x208222>>(v&0x1f))&1;
    }
    string sortVowels(string &s) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<int> v;
        for(char c : s) {
               if(isvowel(c)) {
                   v.push_back(int(c));
               }
        }
        sort(v.begin(), v.end());
        int vi = 0;
        for(int i = 0; i < s.size(); ++i){
            if(isvowel(s[i])) {
                s[i] = char(v[vi]);
                vi++;
            }
        }
        return s;
    }
};