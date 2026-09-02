class Node {
public:
    int key;
    int value;

    Node* prev;
    Node* next;

    Node(int key, int value) {
        this->key = key;
        this->value = value;
        prev = nullptr;
        next = nullptr;
    }
    
};

class LRUCache {
public:
    unordered_map<int,Node*>mp;
    int capacity;
    Node *head;
    Node *tail;
    // Remove a node from the linked list
    void remove(Node* node) {

        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }


    // Insert node just before tail
    void insert(Node* node) {

        Node* prevNode = tail->prev;

        prevNode->next = node;
        node->prev = prevNode;

        node->next = tail;
        tail->prev = node;
    }
    LRUCache(int capacity) {
       this->capacity = capacity;

        // Dummy nodes
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {

        // Key doesn't exist
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        // This key was just used,
        // so it becomes MRU.

        remove(node);
        insert(node);

        return node->value;
    }


    void put(int key, int value) {

        // CASE 1: key already exists
        if (mp.find(key) != mp.end()) {

            Node* node = mp[key];

            // Update value
            node->value = value;

            // Move to MRU
            remove(node);
            insert(node);

            return;
        }


        // CASE 2: new key

        Node* newNode = new Node(key, value);

        mp[key] = newNode;

        insert(newNode);


        // Capacity exceeded
        if (mp.size() > capacity) {

            // First real node after head
            Node* lru = head->next;

            // Remove from map
            mp.erase(lru->key);

            // Remove from linked list
            remove(lru);

            // Free memory
            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */