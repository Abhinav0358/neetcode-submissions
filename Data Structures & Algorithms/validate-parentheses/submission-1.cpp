class Solution {
public:
    bool isValid(string s) {
        stack<char> stck;
        for(char chr : s){
            if(stck.empty()){
                stck.push(chr);
                continue;
            }

            if(chr==']'&&stck.top()=='[')stck.pop();
            else if(chr=='}'&&stck.top()=='{')stck.pop();
            else if(chr==')'&&stck.top()=='(')stck.pop();
            else stck.push(chr);
        }
        
        return stck.empty();
    }
};
