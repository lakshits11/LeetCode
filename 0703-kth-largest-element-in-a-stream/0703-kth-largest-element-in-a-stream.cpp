// By Lakshit Somani
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static int pr = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

// In min Heap, kth largest element will always be at the top.
class KthLargest
{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int size;

    KthLargest(int k, vector<int> &nums)
    {
        size = k;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
            if (pq.size() > k)
                pq.pop();
        }
    }

    int add(int val)
    {
        pq.push(val);
        if (pq.size() > size)
            pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */