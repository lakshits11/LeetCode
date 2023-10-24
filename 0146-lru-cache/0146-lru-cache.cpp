class LRUCache {
public:
    class node {
    public:
        int key;
        int val;
        node* next;
        node* prev;
        
        node(int _key, int _val)
        {
            key = _key;
            val = _val;
        }
    };
    
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    
    int cap;
    unordered_map<int, node*> u;
    
    // Initialisation Step
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(node* newNode)
    {
        node* temp = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = temp;
        temp->prev = newNode;
    }
    
    void deleteNode(node* newNode)
    {
        node* prevNode = newNode->prev;
        node* nextNode = newNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    
    int get(int keyy) {
        if(u.find(keyy) != u.end())
        {
            node* resNode = u[keyy];
            int resVal = resNode->val;
            u.erase(keyy);
            deleteNode(resNode);
            addNode(resNode);
            u[keyy] = head->next;
            return resVal;
        }
        return -1;
    }
    
    void put(int keyy, int value) {
        if(u.find(keyy) != u.end())
        {
            node* existingNode = u[keyy];
            u.erase(keyy);
            deleteNode(existingNode);
        }
        
        if(u.size() == cap)
        {
            u.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        addNode(new node(keyy, value));
        u[keyy] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */