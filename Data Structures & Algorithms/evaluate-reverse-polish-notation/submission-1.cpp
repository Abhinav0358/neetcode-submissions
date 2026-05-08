class Solution {
public:
stack<int> stck;
    int evalRPN(vector<string>& tokens) {
        for(string str: tokens){
            if(str=="+"){
                int a = stck.top();
                stck.pop();
                int b = stck.top();
                stck.pop();
                stck.push(a+b);
            }else if(str=="-"){
                int a = stck.top();
                stck.pop();
                int b = stck.top();
                stck.pop();
                stck.push(b-a);
            }else if(str=="/"){
                int a = stck.top();
                stck.pop();
                int b = stck.top();
                stck.pop();
                stck.push(b/a);
            }else if(str=="*"){
                int a = stck.top();
                stck.pop();
                int b = stck.top();
                stck.pop();
                stck.push(a*b);
            }else stck.push(stoi(str));
        }
        return stck.top();
    }
};
