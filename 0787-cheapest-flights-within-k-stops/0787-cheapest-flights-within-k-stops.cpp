#define tpl tuple<int,int,int>
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int k)
    {
        // pq : (price, node, steps)
        priority_queue<tpl, vector<tpl>, greater<tpl>> pq;
        
        // adj = (node, price)
        vector<pair<int,int>> adj[n];
        
        for(vector<int> fl : flights)
        {
            adj[fl[0]].push_back({fl[1], fl[2]});
        }
        
        vector<int> price(n,INT_MAX);
        vector<int> steps(n, INT_MAX);
        price[src]=0,steps[src]=0;
        
        pq.push({0,src,0});
        
        while(!pq.empty())
        {
            auto [currPrice, currNode, currSteps] = pq.top();
            pq.pop();
            if(currNode==dest)
                return currPrice;
            if(currSteps>=k+1)
                continue;
            for(auto &[newNode, newPrice] : adj[currNode])
            {
                int nextPrice = newPrice + currPrice;
                int nextSteps = currSteps + 1;
                if(nextPrice < price[newNode] || nextSteps < steps[newNode])
                {
                    price[newNode] = nextPrice;
                    steps[newNode] = nextSteps;
                    pq.push({nextPrice, newNode, nextSteps});
                }
            }
        }
        return -1;
        
    }
};