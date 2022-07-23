// By Lakshit Somani
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void mergeSort(int start, int end, vector<pair<int, int>> &new_nums, vector<int> &indices, vector<pair<int, int>> &temp)
    {
        if (start >= end)
            return;

        int mid = (start + end) >> 1;

        mergeSort(start, mid, new_nums, indices, temp);
        mergeSort(mid + 1, end, new_nums, indices, temp);

        int left = start, right = mid + 1;
        int idx = start;

        int nRightLessThanLeft = 0;
        while (left <= mid && right <= end)
        {
            if (new_nums[left].first <= new_nums[right].first)
            {
                indices[new_nums[left].second] += nRightLessThanLeft;
                temp[idx++] = new_nums[left++];
            }
            else if (new_nums[left].first > new_nums[right].first)
            {
                temp[idx++] = new_nums[right++];
                nRightLessThanLeft++;
            }
            // else
            // {
            //     left++;
            //     right++;
            // }
        }

        while (left <= mid)
        {
            indices[new_nums[left].second] += nRightLessThanLeft;
            temp[idx++] = new_nums[left++];
        }
        while (right <= end)
        {
            temp[idx++] = new_nums[right++];
        }
        for (int i = start; i <= end; i++)
        {
            new_nums[i] = temp[i];
        }
    }

public:
    vector<int> countSmaller(vector<int> &nums)
    {
        int n = nums.size();
        vector<pair<int, int>> new_nums; // {nums[i], i}
        vector<pair<int, int>> temp;
        vector<int> indices(n, 0);

        for (int i = 0; i < n; ++i)
        {
            new_nums.push_back({nums[i], i});
            temp.push_back({nums[i], i});
        }
        mergeSort(0, n - 1, new_nums, indices, temp);
        return indices;
    }
};