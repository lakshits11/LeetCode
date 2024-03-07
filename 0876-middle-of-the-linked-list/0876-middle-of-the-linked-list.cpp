static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();
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