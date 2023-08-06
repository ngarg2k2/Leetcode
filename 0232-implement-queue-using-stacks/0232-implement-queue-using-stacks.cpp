class MyQueue {
public:
    MyQueue() {
        
    }
    stack<int>s1;
    stack<int>s2;
    void push(int x) {
        if(s1.empty()){
            s1.push(x);
        }else{
            int n=s1.size();
            for(int i=0;i<n;i++){
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(x);
            n=s2.size();
            for(int i=0;i<n;i++){
                s1.push(s2.top());
                s2.pop();
            }
        }
    }
    
    int pop() {
        int tmp;
        if(s1.empty()){
            return -1;
        }else{
            tmp=s1.top();
            s1.pop();
        }
        return tmp;
    }
    
    int peek() {
        int tmp;
        if(s1.empty()){
            return -1;
        }else{
            tmp=s1.top();
        }
        return tmp;
    }
    
    bool empty() {
        return s1.empty();
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