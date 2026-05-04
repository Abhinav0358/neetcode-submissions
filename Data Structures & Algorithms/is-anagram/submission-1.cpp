class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> counts;
        unordered_map<char,int> countt;
        if(s.size()!=t.size())return false;
        for(char a: s){
            if(!counts[a])counts[a]=0;
            counts[a]++;
        }
        for(char a: t){
            if(!countt[a])countt[a]=0;
            countt[a]++;
        }
        if(counts==countt)return true;
        return false;
    }
};
