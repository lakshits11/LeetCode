/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = NULL;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
            {
                temp = fast;
                cout<<temp->val<<"\n";
                break;
            }
        }
        slow= head;
        while(slow && temp)
        {
            if(slow==temp)  return temp;
            slow=slow->next;
            temp=temp->next;
        }
        return NULL;
        
    }
};