class Solution {
private:
    // For Approach 3
    // function to merge 2 sorted linked lists
    ListNode *merge2Lists(ListNode *a, ListNode *b)
    {
        ListNode *res = NULL;
        if (a == NULL)
            return b;
        if (b == NULL)
            return a;

        if (a->val < b->val)
        {
            a->next = merge2Lists(a->next, b);
            return a;
        }
        b->next = merge2Lists(a, b->next);
        return b;
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0)
            return NULL;

        int start = 0;
        int last = k - 1;
        int temp;

        while (last != 0)
        {
            start = 0;
            temp = last;
            while (start < temp)
            {
                // merge them and store in one linked list
                lists[start] = merge2Lists(lists[start], lists[temp]);
                start++;
                temp--;
                if (start >= temp)
                    last = temp;
            }
        }
        return lists[0];
    }
};