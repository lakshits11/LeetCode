class LRUCache {
public:
    class node{
        public:
            int key;
            int val;
            node *next;
            node *prev;
        node(int _key, int _val)
        {
            key = _key;
            val = _val;
        }
    };
    
    node *head = new node(-1,-1);
    node* tail = new node(-1, -1);
    
    int cap;
    unordered_map<int , node*> m;
    
    void addnode(node *newnode)
    {
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    
    void deletenode(node* delnode)
    {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int k) {
        if(m.find(k) != m.end())
        {
            node* resnode = m[k];
            int res = resnode->val;
            m.erase(k);
            deletenode(resnode);
            addnode(resnode);
            m[k] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int k, int v) {
        if(m.find(k) != m.end())
        {
            node* existingnode = m[k];
            m.erase(k);
            deletenode(existingnode);
        }
        if(m.size() == cap)
        {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(k, v));
        m[k] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */