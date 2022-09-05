class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // https://leetcode.com/problems/merge-k-sorted-lists/discuss/1746240/C%2B%2B-Solution-w-Explanation-or-Step-by-step-optimisation-or-Three-different-approaches
        
        // Apprach1:
        // TC: O(NlogN)
        // SC: O(N)
        int k = lists.size();
        if(k == 0) return NULL;
        
        vector<pair<int, ListNode*>> v;
        for(int i=0;i<k;i++)
        {
            ListNode* curr = lists[i];
            while(curr != NULL)
            {
                v.push_back({curr->val, curr});
                curr = curr->next;
            }
        }
        
        if(v.size()==0) return NULL;
        
        sort(v.begin(), v.end());
        
        for(int i=0;i<v.size()-1;i++)
        {
            v[i].second->next = v[i+1].second;
        }
        
        v[v.size()-1].second->next = NULL;
        return v[0].second;
    }
};