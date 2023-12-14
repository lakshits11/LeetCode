static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

unordered_set<int> s;
class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k)
    {
        int res = 1;
        s.clear();
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