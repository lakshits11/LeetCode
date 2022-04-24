class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        if (k == nums.size())
            return nums;

        map<int, int> m;
        for (int n : nums)
            m[n]++;

        auto comp = [&m](int n1, int n2)
        {
            return m[n1] > m[n2];
        };

        priority_queue<int, vector<int>, decltype(comp)> hp(comp);

        for (pair<int, int> p : m)
        {
            hp.push(p.first);
            if (hp.size() > k)
                hp.pop();
        }

        vector<int> ans(k);
        for(int i=k-1;i>=0 ;i--)
        {
            ans[i]=hp.top();
            hp.pop();
        }
        return ans;
    }
};