class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string s="";
        priority_queue<pair<int,char>> pq;
        if(a>0)pq.push({a,'a'});
        if(b>0)pq.push({b,'b'});
        if(c>0)pq.push({c,'c'});

        while(s.size()<a+b+c){
            char d = pq.top().second;
            int dcount = pq.top().first;
            s+=d;
            pq.pop();
            if(s.size()>1){
                if(s[s.size()-1]==d&&s[s.size()-2]==d){
                if(pq.empty())return s;
                char e = pq.top().second;
                int ecount = pq.top().first;
                s+=e;
                pq.pop();
                if(ecount>1)pq.push({ecount-1,e});
                }
            }           
            if(dcount>1)pq.push({dcount-1,d});
        }
        return s;
    }
};