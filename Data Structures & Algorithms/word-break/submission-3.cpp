class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        vector<int> memo(s.size(),-1);
        string curr="";
        for(string &str: wordDict){
            dict.insert(str);
        }

        return wordBrk(s,dict,0,memo);
    }
    bool wordBrk(string &s, unordered_set<string> &dict, int index,vector<int>&memo) {
        string curr="";
        if(index==s.size())return true;

        if(memo[index]==1)return true;
        if(memo[index]==0)return false;
        for(int i=index; i<s.size(); i++){
            curr+=s[i];
            if(dict.find(curr)!=dict.end()){
                if(wordBrk(s,dict,i+1,memo))return true;                
                // curr="";
            }
        }

        if(curr.size()==0){
            memo[index]=1;
            return true;
        }

        memo[index]=0;
        return false;
    }
};
