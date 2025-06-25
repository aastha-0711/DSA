class Node{
    public:
    int key;
int val;
Node*prev;
Node*next;
Node(int key,int val): key(key), val(val), prev(nullptr), next(nullptr){}
};
class LRUCache {
private:
unordered_map<int, Node*> cache;
Node*head;
Node*tail;
int cap;
   
    private:
    void deleteNode(Node* node){
        Node* prevnode=node->prev;
        Node*nextnode= node->next;
        prevnode->next=nextnode;
        nextnode->prev=prevnode;
    }
    void insertNode(Node* node){
         Node* nextnode = head->next;
        head->next = node;
        node->prev = head;
        node->next = nextnode;
        nextnode->prev = node;

    }
public:

    LRUCache(int capacity) {
        cap=capacity;
        cache.clear();
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
      if(!cache.count(key))return -1;
      Node*node=cache[key];
deleteNode(node);
insertNode(node);

      return node->val;  
    }
 
  
    void put(int key, int value) {
        if(cache.count(key)){
            Node*nodie=cache[key];
            nodie->val=value;
            deleteNode(nodie);
            insertNode(nodie);
        }
        else{
            if(cache.size()==cap){
                Node*lru=tail->prev;
                cache.erase(lru->key);
                deleteNode(lru);
                delete(lru);

            }
            Node * nodee= new Node(key,value);
            cache[key]=nodee;
            insertNode(nodee);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */