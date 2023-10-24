class TrieNode
{
public:
    TrieNode* next[26];
    bool isWord;
    
    TrieNode(bool b = false)
    {
        memset(next, 0, sizeof(next));
        isWord = b;
    }
};


class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string s) {
        TrieNode* p = root;
        for(int i=0;i<s.size();i++)
        {
            if(p->next[s[i]-'a'] == NULL)
                p->next[s[i]-'a'] = new TrieNode();
            p = p->next[s[i]-'a'];
        }
        p->isWord = true;
    }
    
    bool search(string s) {
        TrieNode* p = root;
        for(int i = 0; i < s.size() && p != NULL; ++i)
        {
            p = p->next[s[i]-'a'];
        }
        return p!=NULL && p->isWord;
    }
    
    bool startsWith(string s) {
        TrieNode* p = root;
        for(int i = 0; i < s.size() && p != NULL; ++i)
        {
            p = p->next[s[i]-'a'];
        }
        return p!=NULL;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */