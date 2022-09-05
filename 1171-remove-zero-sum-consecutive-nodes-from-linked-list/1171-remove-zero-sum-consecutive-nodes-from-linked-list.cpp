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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        unordered_map<int, ListNode*> u;
        u[0] = dummy;
        int sum = 0;
        
        while(head)
        {
            sum += head->val;
            
            // found value
            if(u.find(sum) != u.end())
            {
                ListNode* prev = u[sum];
                ListNode* start = prev;
                
                // delete bad refernces
                int aux = sum;
                while(prev != head)
                {
                    prev = prev->next;
                    aux += prev->val;
                    if(prev!=head)  u.erase(aux);
                }
                start->next = head->next;
            }
            else
                u[sum] = head;
            head = head->next;
        }
        return dummy->next;
    }
};