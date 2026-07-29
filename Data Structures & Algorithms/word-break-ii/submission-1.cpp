class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        unordered_set<string> sett(wordDict.begin(),wordDict.end());
        string str="";
        int start=0;
        for(int i=start; i<s.size(); i++){
            string word = s.substr(start,i-start+1);
            if(sett.contains(word)){
                next(s,sett,i+1,(str+word+" "),ans);
            }
        }

        return ans;
        
    }
    void next(string &s, unordered_set<string> &sett,int start, string str, vector<string> &ans){
        if(start>=s.size()){
            str.pop_back();
            ans.push_back(str);
            return;
        }
        for(int i=start; i<s.size(); i++){
            string word = s.substr(start,i-start+1);
            if(sett.contains(word)){
                next(s,sett,i+1,(str+word+" "),ans);
            }
        }
    }
};