class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gs)
    {
        if(hand.size() % gs != 0)
            return false;
        map<int, int> count;
        for(int n : hand)
        {
            count[n]++;
        }
        for(pair<int, int> it : count)
        {
            if(count[it.first] > 0)
            {
                for(int i = gs - 1; i >= 0; i--)
                {
                    count[it.first + i] -= count[it.first];
                    if(count[it.first + i] < 0)
                        return false;
                }
            }
        }
        return true;
    }
};