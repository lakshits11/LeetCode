class Solution {
public:
    vector<string> cellsInRange(string s) {
        ios_base::sync_with_stdio(0);
        vector<string> ans;
        string ref = "0ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int sj = s[1]-'0'; // starting j
        int ej = s[4]-'0'; // ending j
        char sc = s[0]; //starting character
        char ec = s[3]; // ending character
        int si = sc-'A'+1; // starting i
        int ei = ec-'A'+1; // ending i
        for(int i=si;i<=ei;i++)
        {
            for(int j=sj;j<=ej;j++)
            {
                string temp;
                temp.push_back(ref[i]);
                temp.append(to_string(j));
                ans.push_back(temp);
                temp.clear();
            }
        }
        return ans;
    }
};