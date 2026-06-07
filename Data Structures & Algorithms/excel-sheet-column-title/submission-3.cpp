class Solution {
public:
    string convertToTitle(int columnNumber) {
        stack<char> stck;
        char a;
        while(columnNumber>0){
            stck.push('A'+(columnNumber-1)%26);
            cout<<columnNumber<<endl;
            columnNumber=(columnNumber-1)/26;
        }   
        string s;

        while(!stck.empty()){
            s+=stck.top();
            stck.pop();
        }
        return s;
    }
};