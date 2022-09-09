class Solution
{
public:
    ListNode *reversee(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *prev = NULL, *next;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *curr = head, *prev = NULL;
        int count = 1;
        while (count != left)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        ListNode *newHead = curr;
        while (count != right)
        {
            count++;
            curr = curr->next;
        }
        ListNode *rest = curr->next;
        curr->next = NULL;
        newHead = reversee(newHead);
        if (prev != NULL)
            prev->next = newHead;
        curr = newHead;
        while (curr->next)
        {
            curr = curr->next;
        }
        curr->next = rest;
        if (left == 1)
            return newHead;
        return head;
    }
};