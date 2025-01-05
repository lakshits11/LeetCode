class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> pref(n + 1, 0);
        for (vector<int>& a : shifts) {
            if (a[2] == 0)
                a[2] = -1;
            pref[a[0]] = pref[a[0]] + (a[2]);
            pref[a[1] + 1] = pref[a[1] + 1] + -(a[2]);
        }
        for (int i = 1; i < n + 1; i++) {
            pref[i] += pref[i - 1];
        }
        for(int z : pref)
        {
            cout << z << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            int increaseBy = (s[i]-'a'+pref[i])%26;
            increaseBy = (increaseBy+26)%26;
            s[i] = 'a' + increaseBy;
        }
        return s;
    }
};