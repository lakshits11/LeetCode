class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k)
    {
        // ios_base::sync_with_stdio(false);
        int res = 1;
        set<int> s;
        for(int i=0;i<rolls.size();i++)
        {
            s.insert(rolls[i]);
            if(s.size()==k)
            {
                ++res;
                s.clear();
            }
        }
        return res;
    }
};