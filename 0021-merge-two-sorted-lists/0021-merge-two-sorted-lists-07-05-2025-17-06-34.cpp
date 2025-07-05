/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* x, ListNode* y) {
        ListNode* dummy = new ListNode(0, NULL);
        ListNode* temp = dummy;
        while(x && y)
        {
            if(x->val < y->val)
            {
                temp->next = x;
                x = x->next;
                temp = temp->next;
            }
            else {
                temp->next = y;
                y = y->next;
                temp = temp->next;
            }
        }
        // while(x)
        // {
        //     temp->next = x;
        //     x = x->next;
        //     temp = temp->next;
        // }
        // while(y)
        // {
        //     temp->next = y;
        //     y = y->next;
        //     temp = temp->next;
        // }
        // above thing can be written better
        temp->next = x ? x : y;
        temp = dummy->next;
        delete dummy;
        return temp;

    }
};