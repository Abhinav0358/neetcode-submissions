class Solution {
unordered_map<char,int> mp;
public:
    bool isAlienSorted(vector<string>& words, string order) {
        // iterate through words
        // if word ends - end it all
        // just store in chat int hashmap ig

        for(int i=0; i<order.size(); i++){
            mp[order[i]]=i;
        }

        for(int i=0;i<words.size()-1; i++){
            if(!compare(words[i],words[i+1]))return false;
        }
        return true;
    }
    bool compare(const string &word1, const string &word2){
        for(int i=0; i<word1.size(); i++){
            if(i>=word2.size())return false;
            if(mp[word1[i]]<mp[word2[i]])return true;            
            if(mp[word1[i]]>mp[word2[i]])return false;
        }
        return true;
    }
};