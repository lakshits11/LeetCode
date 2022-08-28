class comp{
    public:
    bool operator()(const ListNode* a, const ListNode* b)
    {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k==0)
            return NULL;
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        for(int i=0;i<k;i++)
        {
            if(lists[i]!=NULL)
                pq.push(lists[i]);
        }
        
        ListNode* prev = NULL;
        ListNode* head = NULL;
        while(!pq.empty())
        {
            ListNode* x = pq.top();
            pq.pop();
            if(prev==NULL)
                head = x;
            else prev->next = x;
            
            prev = x;
            if(x->next != NULL)
                pq.push(x->next);
        }
        return head;
        
    }
};