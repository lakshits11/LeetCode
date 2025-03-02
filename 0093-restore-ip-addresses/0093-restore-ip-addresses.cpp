class Solution {
private:
    bool isValid(string &s) {
        if (s.length() > 3 || s.empty())
            return false;

        // 0 is valid, but numbers like "00", "01", "023" are not valid.
        if (s[0] == '0' && s.length() > 1)
            return false;

        int val = stoi(s);
        return (val >= 0 && val <= 255);
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        int n = s.length();

        if (n < 4 || n > 12) // Pruning: Valid IPs must have 4 to 12 characters
            return {};

        for (int i = 1; i <= 3 && i < n; i++) { // 1st partition
            for (int j = i + 1; j <= i + 3 && j < n; j++) { // 2nd partition
                for (int k = j + 1; k <= j + 3 && k < n; k++) { // 3rd partition
                    string a = s.substr(0, i);
                    string b = s.substr(i, j - i);
                    string c = s.substr(j, k - j);
                    string d = s.substr(k);

                    if (isValid(a) && isValid(b) && isValid(c) && isValid(d)) {
                        result.push_back(a + "." + b + "." + c + "." + d);
                    }
                }
            }
        }

        return result;
    }
};