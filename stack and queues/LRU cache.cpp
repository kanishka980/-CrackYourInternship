class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int key, int val) {
        this->key = key;
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};
class LRUCache {
public:
    unordered_map<int, Node*> mp;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void add(Node* p) {
        Node* temp = head->next;
        head->next = p;
        p->prev = head;
        p->next = temp;
        temp->prev = p;
    }
    void delete_node(Node* p) {
        Node* previous = p->prev;
        Node* ne = p->next;
        previous->next = ne;
        ne->prev = previous;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* c = mp[key];
            delete_node(c);
            add(c);
            mp[key] = head->next;
            return head->next->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* a = mp[key];

            delete_node(a);
            a->val = value;
            add(a);
            mp[key] = head->next;

        } else {
            if (mp.size() == cap) {
                Node* tail_pre = tail->prev;
                delete_node(tail_pre);
                Node* l = new Node(key, value);
                add(l);
                mp.erase(tail_pre->key);
                mp[key] = head->next;

            } else {
                Node* l = new Node(key, value);
                add(l);
                mp[key] = head->next;
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
