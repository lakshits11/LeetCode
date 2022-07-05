class Solution
{
public:
    string mostCommonWord(string para, vector<string> &banned)
    {
    	ios_base::sync_with_stdio(false);cin.tie(nullptr);
        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> count;
        for (auto &c : para)
            c = isalpha(c) ? tolower(c) : ' ';
        cout << para << "\n";
        istringstream iss(para);
        string w;
        pair<string, int> res("", 0);
        while (iss >> w)
        {
            if (ban.find(w) == ban.end() && ++count[w] > res.second)
                res = make_pair(w, count[w]);
        }
        return res.first;
    }
};
