/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* f = head;
        ListNode* s = head;
        while(f && f->next)
        {
            s = s->next;
            f = f->next->next;
            if(f == s)
                return true;
        }
        return false;
    }
};