class MinStack {
public:
stack<int> stck;
stack<int> minstck;
int min;
    MinStack() {
        
    }
    
    void push(int val){
        if(stck.empty()){
            minstck.push(val);
            stck.push(val);
            min=val;
            return;
        }
        stck.push(val);
        if(val<=min){
            minstck.push(val);
            min=val;
        }
    }
    
    void pop() {
        if(stck.top()==minstck.top())minstck.pop();
        stck.pop();
    }
    
    int top() {
        return stck.top();
    }
    
    int getMin() {
        return minstck.top();
    }
};
