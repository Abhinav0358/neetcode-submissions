class Solution {
public:
    bool checkValidString(string s) {
        
        return check(s,0,0);
        return false;
    }bool check(string &s, int index, int val){
        if(val<0)return false;
        if(index>=s.size()){
            if(val==0)return true;
            return false;
        }
        if(val>s.size()-index)return false;
        char c = s[index];
        if(c=='(')return check(s,index+1,val+1);
        if(c==')')return check(s,index+1,val-1);
        if(c=='*')return check(s,index+1,val-1)||check(s,index+1,val+1)||check(s,index+1,val);
        return false;
    }
};
