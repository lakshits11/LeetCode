// By Lakshit Somani
#include <bits/stdc++.h>
using namespace std;

static int arr[201];

static const auto speedup = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(arr, -1, sizeof(arr));
    return 0;
}();

class Solution
{
public:
    int numberOfMatches(int n)
    {
        if (arr[n] != -1) return arr[n];
        int ans = 0, tmp = n;
        while (n > 1)
        {
            if (n % 2 == 0)
            {
                n /= 2;
                ans += n;
            }
            else
            {
                n = ((n - 1) / 2) + 1;
                ans += (n - 1);
            }
        }
        return arr[tmp] = ans;
    }
};