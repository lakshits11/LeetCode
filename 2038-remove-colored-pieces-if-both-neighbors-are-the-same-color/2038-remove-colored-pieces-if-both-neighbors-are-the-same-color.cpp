auto speed=[]() { std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return nullptr;}();
class Solution {
public:
    bool winnerOfGame(string colors) {
        // ios_base::sync_with_stdio(false);
        int ca = 0, cb = 0;
        if(colors.size() < 3)
            return false;
        string temp;
        for(int i=0;i<colors.size()-2;i++)
        {
            temp = colors.substr(i,3);
            // cout << temp << "\n";
            if(temp == "AAA")
                ca++;
            else if(temp == "BBB")
                cb++;
        }
        return ca > cb;
    }
};