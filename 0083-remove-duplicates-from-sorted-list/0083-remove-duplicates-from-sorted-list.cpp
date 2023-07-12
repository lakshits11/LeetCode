class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *t = head;
        while(t)
        {
            while(t->next && t->next->val == t->val)
            {
                t->next = t->next->next;
            }
            t = t->next;
        }
        return head;
    }
};