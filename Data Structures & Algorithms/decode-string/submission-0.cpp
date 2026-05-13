class Solution {
public:
    string decodeString(string s) {
        int no=0;
        string str="";
        stack<pair<string,int>> stck;

        for(char chr : s){
            if(isdigit(chr)){
                no = no * 10 + (chr - '0');
                continue;
            }
            if(chr=='['){
                stck.push({str,no});
                no=0;
                str="";
                continue;
            }
            if(chr==']'){
                string tmp="";
                for(int i=0; i<stck.top().second; i++){
                    tmp+=str;
                }
                stck.top().first+=tmp;
                str=stck.top().first;
                stck.pop();
                continue;
            }
            str.push_back(chr);
        }
        return str;
    }
};