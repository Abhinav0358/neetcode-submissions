class Solution {
public:
    string reorganizeString(string s) {
        // umm 
        // lets do a pattern like abcd abcd
        // easy
        // but abbcccdddd
        // abcdbcdcdd this is bad - could have used just a hashmap but ig need to use heap for starting with 
        // the highest freq
        // ddddcccbba
        // dcbadcbdcd
        // works


        // nahhh
        //  doesn't work
        // whenever u have to get max / min out of a changing list use a heap

        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> mp;

        for(char c : s){
            mp[c]++;
        }
        for(auto& a : mp){
            pq.push({a.second,a.first});
        }
        string ans="";
        while(ans.size()<s.size()){
            char a = pq.top().second;
            int acount = pq.top().first;
            pq.pop();
            ans+=a;
            if(pq.empty()&&acount>1)return "";
            if(!pq.empty()){
            char b = pq.top().second;
            int bcount = pq.top().first;
            pq.pop();
            ans+=b;
            if(bcount>1)pq.push({bcount-1,b});
            }
            if(acount>1)pq.push({acount-1,a});
        }
        return ans;
    }
};