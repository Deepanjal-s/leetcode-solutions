#include <iostream>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    struct Node {
        int val;
        int key;
        Node* prev;
        Node* next;

        Node(int v, int k){
            val = v;
            key = k;
            prev = NULL;
            next = NULL;
        }
    };

    int cap;
    unordered_map<int , Node*> cache;

    Node* head = new Node(0,0);
    Node* tail = new Node(0,0);
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()){
            return -1;
        }
        Node* node = cache[key];
        remove(node);
        insert(node);
        return node->val;
    }
    
    void put(int key, int value) {
        
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            node->val = value;
            remove(node);
            insert(node);
            return;
        }

        Node* node = new Node(value,key);
        
        if(cap <= cache.size()){
            Node* lru = head->next;
            cache.erase(lru->key);
            remove(lru);
            insert(node);
            cache[key] = node;
        }else{
            insert(node);
            cache[key] = node;
        }
        
    }

    void remove(Node* node){
        if(node == NULL){
            return;
        }
        Node* nodePrev = node->prev;
        Node* nodeNext = node->next;
        nodePrev->next = nodeNext;
        nodeNext->prev = nodePrev;
    }

    void insert(Node* node){
        if(node == NULL){
            return;
        }
        Node* nodePrev = tail->prev;
        nodePrev->next = node;
        node->next = tail;
        node->prev = nodePrev;
        tail->prev = node;
    }
};
