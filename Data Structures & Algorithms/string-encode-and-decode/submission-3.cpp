class Solution{
public:

    string encode(vector<string>& strs) {
        string result="";
        for(string str: strs){
            result+=str;
            result+='\n';        
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        string word;
        for(char a: s){
            if(a=='\n'){
                result.push_back(word);
                word="";
                continue;
            }
            word.push_back(a);
        }
        return result;
    }
};
