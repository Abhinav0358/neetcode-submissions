class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string currstr;
        if(digits.size()==0)return ans;
        backtrack(digits,0, ans,currstr);
        return ans;
    }
    void backtrack(string &digits, int index, vector<string> &ans, string currstr){
        if(currstr.size()==digits.size()){
            ans.push_back(currstr);
            return;
        }
        if(index>=digits.size())return;
        if(digits[index]=='2'){
            backtrack(digits,index+1,ans,currstr+"a");
            backtrack(digits,index+1,ans,currstr+"b");
            backtrack(digits,index+1,ans,currstr+"c");
        }else if(digits[index]=='3'){
            backtrack(digits,index+1,ans,currstr+"d");
            backtrack(digits,index+1,ans,currstr+"e");
            backtrack(digits,index+1,ans,currstr+"f");
        }else if(digits[index]=='4'){
            backtrack(digits,index+1,ans,currstr+"g");
            backtrack(digits,index+1,ans,currstr+"h");
            backtrack(digits,index+1,ans,currstr+"i");
        }else if(digits[index]=='5'){
            backtrack(digits,index+1,ans,currstr+"j");
            backtrack(digits,index+1,ans,currstr+"k");
            backtrack(digits,index+1,ans,currstr+"l");
        }else if(digits[index]=='6'){
            backtrack(digits,index+1,ans,currstr+"m");
            backtrack(digits,index+1,ans,currstr+"n");
            backtrack(digits,index+1,ans,currstr+"o");
        }else if(digits[index]=='7'){
            backtrack(digits,index+1,ans,currstr+"p");
            backtrack(digits,index+1,ans,currstr+"q");
            backtrack(digits,index+1,ans,currstr+"r");
            backtrack(digits,index+1,ans,currstr+"s");
        }else if(digits[index]=='8'){
            backtrack(digits,index+1,ans,currstr+"t");
            backtrack(digits,index+1,ans,currstr+"u");
            backtrack(digits,index+1,ans,currstr+"v");
        }else if(digits[index]=='9'){
            backtrack(digits,index+1,ans,currstr+"w");
            backtrack(digits,index+1,ans,currstr+"x");
            backtrack(digits,index+1,ans,currstr+"y");
            backtrack(digits,index+1,ans,currstr+"z");
        }
    }
};
