int init = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ofstream out("user.out");
    cout.rdbuf(out.rdbuf());
    for (string line; getline(cin, line); cout << '\n') {
        istringstream ss(line);
        char ch;
        int a, b, c, d;
        ss >> ch >> ch >> a >> ch >> b >> ch >> ch >> ch >> c >> ch >> d;
        if (a == c || a == d) cout << a;
        else cout << b;
    }
    exit(0);
    return 0;
}();

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int>adj;
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]]++;
            adj[edges[i][1]]++;
        }
        int temp = 0;
        int ans = 0;
        for(auto it : adj) {
            if(it.second > temp) {
                temp = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};