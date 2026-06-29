class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> smap;
        unordered_map<char,int> tmap;
        int smaller=0;
        int larger=s.size();
        for(char c : t){
            tmap[c]++;
        }

        int start=0;
        int end=0;

        while(end<s.size()){
            if(end<s.size())smap[s[end]]++;
            while(isvalid(smap,tmap)){
                if(end-start<larger-smaller){
                    larger=end;
                    smaller=start;
                }
                smap[s[start]]--;
                start++;
            }
            end++;
        }

    
        if(larger==s.size()) return "";
        return s.substr(smaller, larger-smaller+1);


    }
    bool isvalid(unordered_map<char,int> &smap, unordered_map<char,int> &tmap){
        for(auto & p : tmap){
            if(smap[p.first]<p.second)return false;
        }
        return true;
    }
};
