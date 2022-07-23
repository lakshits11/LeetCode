// By Lakshit Somani
#include <bits/stdc++.h>
using namespace std;
#define tpl tuple<int, int, int>

class Solution
{
public:
    int minCost(int maxTime, vector<vector<int>> &edges, vector<int> &passingFees)
    {
        int n = passingFees.size();
        vector<pair<int, int>> adj[n];
        for (vector<int> edge : edges)
        {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        // {cost, node, time}
        priority_queue<tpl, vector<tpl>, greater<tpl>> pq;
        vector<int> cost(n, 1e9);
        vector<int> timer(n, 1e9);
        cost[0] = passingFees[0], timer[0] = 0;
        pq.emplace(cost[0], 0, 0);

        while (!pq.empty())
        {
            auto [currCost, currNode, currTime] = pq.top();
            pq.pop();

            if (currNode == n - 1)
                return currCost;
            // if (currTime > maxTime)
            //     continue;

            for (pair<int, int> x : adj[currNode])
            {
                int newNode = x.first;
                int newTime = currTime + x.second;
                if (newTime <= maxTime && (cost[newNode] > currCost + passingFees[newNode] || timer[newNode] > newTime))
                {
                    pq.emplace(currCost + passingFees[newNode], newNode, newTime);
                    // if(cost[newNode] > currCost + passingFees[newNode])
                        cost[newNode] = currCost + passingFees[newNode];
                    // if(timer[newNode] > newTime)
                        timer[newNode] = newTime;
                }
            }
        }
        return -1;
    }
};
