class Solution {
public:
    int furthestBuilding(vector<int>& ht, int bricks, int ladders) {
        priority_queue<int> pq;
        int i = 0, diff = 0;
        // https://leetcode.com/problems/furthest-building-you-can-reach/discuss/2176644/C%2B%2B-oror-Easy-Solution-oror-Full-Explanation
        for(i = 0; i < ht.size() - 1; i++)
        {
            diff = ht[i+1] - ht[i];
            if(diff <= 0)
                continue;
            
            bricks -= diff;
            pq.push(diff);
            
            if(bricks < 0)
            {
                bricks += pq.top();
                ladders--;
                pq.pop();
            }
            if(ladders < 0)
                break;
        }
        return i;
    }
};