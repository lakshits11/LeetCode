static const auto speedup = []() -> int
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    long long dividePlayers(vector<int> &skill)
    {
        long long ans = 0;
        int mp[100005] = {0};
        long sum = 0, count = 0, n = skill.size() / 2;
        for (int &s : skill)
            sum += s;
        if (sum % n != 0) return -1;
        int teamSize = sum / n;
        for (int &s : skill)
        {
            if (mp[teamSize - s] > 0)
            {
                // since we have already considered current element, so we need not consider its complimentary element, mthats why we did reduce count of its complimentary element
                mp[teamSize - s]--;
                ans += s * (teamSize - s);
                count--;
            }
            else
            {
                mp[s]++;
                count++;
            }
        }
        if (count != 0) return -1;
        return ans;
    }
};