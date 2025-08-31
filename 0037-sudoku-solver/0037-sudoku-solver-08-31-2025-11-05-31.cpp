class Solution {
private:
    vector<unordered_set<char>> vr;
    vector<unordered_set<char>> vc;
    vector<unordered_set<char>> vb;

public:
    bool isValid(int i, int j, char x) {
        int box = (i / 3) * 3 + (j / 3);
        if (vr[i].find(x) == vr[i].end() && vc[j].find(x) == vc[j].end() &&
            vb[box].find(x) == vb[box].end()) {
            return true;
        }
        return false;
    }
    bool solve(vector<vector<char>>& b) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (b[i][j] == '.') {
                    for (char x = '1'; x <= '9'; x++) {
                        if (isValid(i, j, x)) {
                            b[i][j] = x;
                            vr[i].insert(x);
                            vc[j].insert(x);
                            int box = (i / 3) * 3 + (j / 3);
                            vb[box].insert(x);
                            if (solve(b))
                                return true;
                            else {
                                b[i][j] = '.';
                                vr[i].erase(x);
                                vc[j].erase(x);
                                vb[box].erase(x);
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& b) {
        vr.resize(9);
        vc.resize(9);
        vb.resize(9);
        int box;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (b[i][j] != '.') {
                    vr[i].insert(b[i][j]);
                    vc[j].insert(b[i][j]);

                    box = (i / 3) * 3 + (j / 3);
                    vb[box].insert(b[i][j]);
                }
            }
        }

        solve(b);
    }
};