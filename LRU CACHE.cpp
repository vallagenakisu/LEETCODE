#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    Node *prev;
    Node *next;
    int val;
    int key;
    Node(){
        val = 0;
        key = 0;
        prev = NULL;
        next = NULL;
     }  
    Node( int _val , int _key ){
        val = _val;
        key = _key;
        prev = NULL;
        next = NULL;
    }
};
class LRUCache {

public:
    int cap;
    unordered_map<int,Node*> cache;
    Node *left;
    Node *right;


    void insert(Node *node){
        node->next = right;
        node->prev = right->prev;
        right->prev->next = node;
        right->prev = node ;

    }
    void remove(Node *node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        left = new Node();
        right = new Node();
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            int ans =  cache[key]->val;
            remove(cache[key]);
            insert(cache[key]);
            return ans;
        }
        return -1 ;
        
        
    }
    
    void put(int key, int value) {
        if( cache.find(key) != cache.end())
        {
            remove(cache[key]);
        }
            Node *newnode = new Node(value,key);
            cache[key] = newnode;
            insert(newnode);
        if(cache.size() > cap){
            Node *LRU = left->next;
            remove(LRU);
            cache.erase(LRU->key);
            delete LRU;
        } 
    }
};

int main()
{

}