#include <bits/stdc++.h>
using namespace std;

struct node {
    int val;
    int key;
    node* next;
    node* pre;
    node(int x, int k) : val(x), key(k), next(NULL), pre(NULL) {}
};


class LRUCache {
    unordered_map<int, node*> hash;
    node* head;
    node* tail;
    int freeSize;
public:
    LRUCache(int capacity) {
        head = new node(0, INT_MIN);
        tail = new node(0, INT_MIN);
        head -> next = tail;
        tail -> pre = head;
        freeSize = capacity;
    }
    
    int get(int key) {
        if (hash.find(key) == hash.end()) return -1;
        node* str = hash[key];
        str -> pre -> next = str -> next;
        str -> next -> pre = str -> pre;
        str -> pre = head;
        head -> next -> pre = str;
        str -> next = head -> next;
        head -> next = str;
        return str -> val;
    }
    
    void put(int key, int value) {
        if (hash.find(key) != hash.end()) {
            hash[key] -> val = value;
            get(key);
            return;
        }
        if (freeSize) {
            node* str = new node(value, key);
            head -> next -> pre = str;
            str -> next = head -> next;
            head -> next = str;
            str -> pre = head;
            hash[key] = str;
            freeSize--;
            return;
        } 
        node* str = tail -> pre;
        str -> pre -> next = tail;
        tail -> pre = str -> pre;
        hash.erase(str -> key);
        delete str;
        str = new node(value, key);
        head -> next -> pre = str;
        str -> next = head -> next;
        head -> next = str;
        str -> pre = head;
        hash[key] = str;
    }
};
