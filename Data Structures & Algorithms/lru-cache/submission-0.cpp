struct DLL {
    int key, value;
    DLL *prev, *next;
    DLL(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
    int capacity;
    unordered_map<int, DLL*> cache;
    DLL* head;
    DLL* tail;

    void remove(DLL* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAtTail(DLL* node) {
        node->prev = tail->prev;
        node->next = tail;
        tail->prev->next = node;
        tail->prev = node;
    }

public:
    LRUCache(int capacity) : capacity(capacity) {
        head = new DLL(0, 0);
        tail = new DLL(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.count(key)) {
            DLL* node = cache[key];
            remove(node);
            insertAtTail(node);
            return node->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.count(key)) {
            cache[key]->value = value;
            remove(cache[key]);
            insertAtTail(cache[key]);
        } else {
            if ((int)cache.size() == capacity) {
                DLL* lru = head->next;
                remove(lru);
                cache.erase(lru->key);
                delete lru;
            }
            DLL* node = new DLL(key, value);
            insertAtTail(node);
            cache[key] = node;
        }
    }
};