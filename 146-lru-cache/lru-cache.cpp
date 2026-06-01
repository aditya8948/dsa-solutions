class LRUCache {
public:
    struct Node{
        int key;
        int val;
        struct Node* prev;
        struct Node* next;
        Node(int k , int v){
            key = k;
            val = v;
            prev = NULL;
            next = NULL;
        }
    };
    unordered_map<int , Node* > kmap;
    struct Node* head;
    struct Node* tail;
    int maxSize, currSize;

    LRUCache(int capacity) {
        maxSize = capacity;
        currSize = 0;
        head = NULL;
        tail = NULL;
    }
    
    Node* addToTail(int k, int v){
        Node* n = new Node(k , v);

        if(!tail) {
            head = n;
            tail = n;
            currSize++;
            return n;
        }
        else{
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
        currSize++;
        return n;
    }

    void moveToTail(Node* node, int val){
        node->val = val;
        if(node == tail) return ;
        if(node == head){
            head = head->next;
            head->prev = NULL;
        }
        else{
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        node->prev = tail;
        tail->next = node;
        node->next = NULL;
        tail = node;
    }

    void deleteAtHead(){
        Node* tmp = head;
        head = head->next;
        if(head) head->prev = NULL;
        else{
            tail = head;
        }
        delete(tmp);
        currSize--;
    }

    int get(int key) {
        if(kmap.count(key) == 0){
            return -1;
        }
        else{
            Node* n = kmap[key];
            int ans = n->val;
            moveToTail(n , ans);
              return ans;
        }
    }
    
    void put(int key, int value) {
        if(kmap.count(key) == 1){
            moveToTail(kmap[key],value);
            return ;
        }
        else{
            if(currSize < maxSize){
                kmap[key] = addToTail(key , value);
            }
            else{
                kmap.erase(head->key);
                deleteAtHead();
                kmap[key] = addToTail(key , value);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */