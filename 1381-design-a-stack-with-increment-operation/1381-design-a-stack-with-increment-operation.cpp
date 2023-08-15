class CustomStack {
public:
    vector<int>arr;
    int sz;
    CustomStack(int maxSize) {
        sz=maxSize;
    }
    
    void push(int x) {
        if(arr.size()<sz){
            arr.push_back(x);
        }
    }
    
    int pop() {
        if(arr.size()==0){
            return -1;
        }else{
            int tmp=arr[arr.size()-1];
            arr.pop_back();
            return tmp;
        }
    }
    
    void increment(int k, int val) {
        int x=k;
        if(k>arr.size()){
            x=arr.size();
        }
        for(int i=0;i<x;i++){
            arr[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */