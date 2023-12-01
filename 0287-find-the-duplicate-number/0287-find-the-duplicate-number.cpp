// By Lakshit Somani
#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/find-the-duplicate-number/discuss/1892921/9-Approaches%3A-Count-Hash-In-place-Marked-Sort-Binary-Search-Bit-Mask-Fast-Slow-Pointers

Marking visited value within the array
Since all values of the array are between 1 to n and the array size is n+1, while scanning the array from left to right, we set the nums[i] to its negative value.

for (int i = 0; i < nums.size(); ++i)
{
    if (nums[abs(nums[i])] < 0)
        return abs(nums[i]);
    nums[abs(nums[i])] = -nums[abs(nums[i])];
}

TC:O(n)
SC:O(1)

// But array is modified in it. !!

// Best approach is to use linkedlist type cycle detection/ duplicate detection

This problem is the same as problem 142, Linked List Cycle II. You can refer to that solution for an explanation of the slow-fast pointer approach to solving this problem.

The key is to understand how to treat the input array as a linked list.

Taking the array [1,3,4,2] as an example, the index of this array is [0, 1, 2, 3], and we can map the index to the nums[n].

0 -> 1 -> 3 -> 2 -> 4 -> 2 -> 4...

Start from nums[n] as a new index and so on until the index exceeds the bounds. This produces a sequence similar to a linked list.

0 -> 1 -> 3 -> 2 -> 4 -> null

If there are repeated numbers in the array, taking the array [1,3,4,2,2] as an example,

0 -> 1 -> 3 -> 2 -> 4 -> 2 -> 4 -> 2

Similarly, the linked list is like this:

0 -> 1 -> 3 -> 2 -> 4 -> 2 -> 4 -> 2 -> ...

Here, 2 -> 4 is a cycle. Then, this linked list can be abstracted as the following figure:

https://assets.leetcode.com/users/images/aeb3e536-9615-466c-a2de-88a9a59ef255_1648626512.666411.png

*/

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int slow = 0, fast = 0;
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = 0;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
