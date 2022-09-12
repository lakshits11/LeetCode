class Solution {
public:
    int bagOfTokensScore(vector<int> &tokes, int power) {
        sort(tokes.begin(), tokes.end());
        int ans = 0;
        int i = 0, j = tokes.size() - 1, points = 0;
        while(i <= j)
        {
            if(power >= tokes[i])
            {
                ans = max(ans, ++points);
                power -= tokes[i++];
            }
            else if(points >= 1)
            {
                ans = max(ans, --points);
                power += tokes[j--];
            }
            else break;
        }
        return ans;
    }
};