struct Node {
    const string &word;
    int index;
    Node(const string &word, int index) : word(word), index(index) {} 
};

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<Node> buckets[26];
        for(string &word : words)
        {
            char startChar = word[0];
            buckets[startChar-'a'].emplace_back(word, 0);
        }
        int ans = 0;
        for(char c : s)
        {
            vector<Node> currBucket = buckets[c-'a'];
            buckets[c-'a'].clear();
            for(Node &node : currBucket)
            {
                ++node.index;
                if(node.index == node.word.size())
                    ans++;
                else
                    buckets[node.word[node.index] - 'a'].push_back(node);
            }
        }
        return ans;
    }
};