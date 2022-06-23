class Solution
{
public:
    bool canReorderDoubled(vector<int> &arr)
    {
        map<int, int> mp;
        for (auto &i : arr)
            mp[i]++;

        while (mp.size() > 0)
        {
            int least = (*mp.begin()).first;
            int target;

            if (least == 0)
            {
                if (mp[least] & 1)
                    return false;
                mp.erase(0);
            }

            else
            {
                if (least < 0)
                {
                    if (least & 1) return false;
                    target = least / 2;
                }
                else target = least * 2;

                int mi = min(mp[least], mp[target]);
                if (mi == 0) return false;

                mp[target] -= mi;
                mp[least] -= mi;

                // it means if freq of target or least becomes zero, remove them from map
                if (!mp[target]) mp.erase(target);
                if (!mp[least]) mp.erase(least);
            }
        }
        return true;
    }
};