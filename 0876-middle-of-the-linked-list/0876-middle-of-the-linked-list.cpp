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
    ListNode* middleNode(ListNode* head) {
        int count=0;
        ListNode* t = head;
        ListNode* p = head;
        while(t!=NULL){
            t=t->next;
            count++;
        }
        int x = (count/2) + 1;
        for(int i=1;i<x;i++)
        {
            p=p->next;
        }
        return p;
    }
};