// class MyStack {
// public:
// queue<int> que1;
// queue<int> que2;
//     MyStack() {

//     }
    
//     void push(int x) {
//         que1.push(x);
//     }
    
//     int pop(){
//         while(que1.size()>1){
//             que2.push(que1.front());
//             que1.pop();
//         }
//         int tp = que1.front();
//         que1.pop();
//         swap(que1,que2);
//         return tp;
//     }
    
//     int top() {
//         while(que1.size()>1){
//             que2.push(que1.front());
//             que1.pop();
//         }
//         int tp = que1.front();
//         que1.pop();
//         que2.push(tp);
//         swap(que1,que2);
//         return tp;
//     }
    
//     bool empty() {
//         return que1.empty();
//     }
// };

// /**
//  * Your MyStack object will be instantiated and called as such:
//  * MyStack* obj = new MyStack();
//  * obj->push(x);
//  * int param_2 = obj->pop();
//  * int param_3 = obj->top();
//  * bool param_4 = obj->empty();
//  */




class MyStack {
public:
queue<int> que;
    MyStack() {

    }
    
    void push(int x) {
        que.push(x);
        int n = que.size();
        for(int i=0; i<n-1; i++){
            que.push(que.front());
            que.pop();
        }
    }
    
    int pop(){
        int tp = que.front();
        que.pop();
        return tp;
    }
    
    int top() {
        return que.front();
    }
    
    bool empty() {
        return que.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */