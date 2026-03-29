class Solution {
public:
    bool checkStrings(string s1, string s2) { // This is LC 2840
        int n = s1.size();
        
        // Arrays to count frequencies of characters at even and odd indices
        vector<int> evenCount(26, 0);
        vector<int> oddCount(26, 0);
        
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                evenCount[s1[i] - 'a']++; // Add for s1
                evenCount[s2[i] - 'a']--; // Subtract for s2
            } else {
                oddCount[s1[i] - 'a']++;
                oddCount[s2[i] - 'a']--;
            }
        }
        
        // If s1 and s2 can be made equal, all frequencies must net to 0
        for (int i = 0; i < 26; i++) {
            if (evenCount[i] != 0 || oddCount[i] != 0) {
                return false;
            }
        }
        
        return true;
    }
};