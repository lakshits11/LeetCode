class Solution {
public:
    /*
        min path of a graph: each vertex is a word in the dictionary list
        
        How to backtrack path in Dijkstra or BFS?
        
        from end, for all adjacent nodes to end, if dist[adj] + 1 = dist[end], adj is a node in the min path.
        
        end. --- a   dist[a] + 1 ==? dist[end]
             |-- b
             |-- c
        
        BFS solution, use dist[i] record the min path of each word from src
    */
    unordered_set<string> dict;
    unordered_map<string, int> dist;
    string src, dst;
    
    vector<vector<string>> res;
    vector<string> path;
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        src = beginWord, dst = endWord;
        for (auto& word : wordList) dict.insert(word);
        queue<string> que;
        dist[src] = 0;
        que.push(src);
        while (!que.empty()) {
            auto t = que.front();
            que.pop();
            if (t == dst) break;
            string bk = t;
            for (int i = 0; i < t.size(); i++) {
                t = bk;  
                // enumerate all possible adjacent words
                for (int j = 'a'; j <= 'z'; j++) {
                    t[i] = j;
                    // if in dictionary and dist has not been updated
                    if (dict.count(t) && dist.count(t) == 0) {
                        dist[t] = dist[bk] + 1;
                        que.push(t);
                    }
                }
            }
        }
        
        // backtrack path
        if (dist.count(dst)) {
            path.push_back(dst);
            dfs(dst);
        }
        
        return res;
    }
    
private:
    
    // cannot use reference here
    void dfs(string u) {
        if (u == src) {
            reverse(path.begin(), path.end());
            res.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }
        
        string bk = u;
        for (int i = 0; i < u.size(); i++) {
            u = bk;
            for (int j = 'a'; j <= 'z'; j++) {
                u[i] = j;
                if (dist.count(u) && dist[u] + 1 == dist[bk]) {
                    path.push_back(u);
                    dfs(u);
                    path.pop_back();
                }
            }
        }
    }
};