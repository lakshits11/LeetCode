class Solution
{
public:
    vector<int> maxSlidingWindow(const vector<int> &A, int k)
    {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);
        deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < A.size(); ++i)
        {
            // [3,3,4,4,7...] and k=3
            while (!dq.empty() && dq.back() < A[i])
                dq.pop_back();
            dq.push_back(A[i]);
            if (i + 1 >= k)
            {
                ans.push_back(dq.front());
                // window reached length k and ab wo (starting element of window) window m nhi rhega to if that element was present ind eque then we remove that element
                if (A[i + 1 - k] == dq.front())
                    dq.pop_front();
            }
        }
        return ans;
    }
};