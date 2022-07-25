class compare{
    public:
    bool operator()(const ListNode* a, const ListNode*b)
    {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        ios_base::sync_with_stdio(false);
        int k = lists.size();
        if(k == 0)   return NULL;
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        
        // pushing first nodes of all lists in pq
        for(int i = 0; i < k; i++)
        {
            if(lists[i]!=NULL)
                pq.push(lists[i]);
        }
        
        ListNode* prev = NULL;
        ListNode* head = NULL;
        
        while(!pq.empty())
        {
            ListNode* node = pq.top();
            pq.pop();
            if(prev == NULL)
                head = node;
            else
                prev->next = node;
            prev = node;
            
            if(node->next != NULL)
                pq.push(node->next);
        }
        
        return head;
    }
};