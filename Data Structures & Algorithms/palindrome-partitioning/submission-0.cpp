class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> currans;
        vector<vector<string>>result;
        backtrack(s,0,currans, result);
        return result;
    }
    void backtrack(string &s, int start, vector<string> &currans, vector<vector<string>> &result){
            if(start>=s.size()){
                result.push_back(currans);
                return;
            }
        for(int i=start; i<s.size(); ++i){
            if(ispalindrome(s,start,i)){
                currans.push_back(s.substr(start, i-start+1));
                backtrack(s,i+1,currans,result);
                currans.pop_back();
            }
        }
    }
    bool ispalindrome(string &s, int start, int end){
        while(start<end){
            if(s[start]!=s[end])return false;
            start++;
            end--;
        }
        return true;
    }
};
