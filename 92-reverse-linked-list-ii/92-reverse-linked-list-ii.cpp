class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        if (head == NULL || left == right)
            return head;
        ListNode *tail = NULL, *temp = NULL;
        ListNode *dummy = new ListNode(0), *prev = dummy;
        dummy->next = head;
        for (int i = 0; i < left - 1; i++)
        {
            prev = prev->next;
        }
        tail = prev->next;
        for (int i = 0; i < right - left; i++)
        {
            temp = prev->next;
            prev->next = tail->next;
            tail->next = tail->next->next;
            prev->next->next = temp;
        }
        return dummy->next;
    }
};