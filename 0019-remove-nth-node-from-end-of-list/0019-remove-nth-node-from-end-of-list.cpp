static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *fast = dummy;
        ListNode *slow = dummy;

        for (int i = 0; i < n; ++i)
        {
            fast = fast->next;
        }
        while (fast != NULL and fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;

        return dummy->next;
    }
};