class MyQueue {
    vector<int> queue;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
queue.push_back(x);
    }
    
    int pop() {
        if(!queue.empty()){
            int front=queue.front();
            queue.erase(queue.begin());
            return front;
        }return -1;
    }
    
    int peek() {
        if(queue.empty()){
            return -1;
        }
        else{
            return queue.front();
        }
    }
    
    bool empty() {
        return queue.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */