// By Lakshit Somani
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<int> dist(n + 1);
        for (int i = 1; i < n + 1; ++i)
            dist[i] = INT_MAX;
        unordered_map<int, vector<pair<int, int>>> graph;
        for (int i = 0; i < times.size(); ++i)
            graph[times[i][0]].push_back({times[i][1], times[i][2]});
        dist[k] = 0;
        queue<pair<int, int>> q;
        // q is storing { distance of node from source, node }
        q.push({0, k});
        while (!q.empty())
        {
            auto temp = q.front();
            q.pop();
            for (int i = 0; i < graph[temp.second].size(); ++i)
            {
                // for each adjacent node p
                auto p = graph[temp.second][i];
                // p.second is distance of p from temp
                // dist[p.first] is distance of p from src
                if (temp.first + p.second < dist[p.first])
                {
                    dist[p.first] = temp.first + p.second;
                    q.push({temp.first + p.second, p.first});
                }
            }
        }
        int val = 0;
        for (int i = 0; i < dist.size(); ++i)
        {
            if (dist[i] == INT_MAX)
                return -1;
            else
                val = max(val, dist[i]);
        }
        return val;
    }
};
