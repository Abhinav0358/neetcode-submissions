class TimeMap {
unordered_map<string,vector<pair<string,int>>> timemap;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timemap[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        // for(int i=timemap[key].size()-1; i>=0; i--){
        //     if(timemap[key][i].second<=timestamp)return timemap[key][i].first;
        // }
        // return "";
        int left = 0;
        int right = timemap[key].size()-1;
        if(timemap[key].size()==0)return "";
        if(timemap[key].size()==1){
            if(timestamp>=timemap[key][0].second)return timemap[key][0].first;
            else return "";
        }
        if(timestamp==timemap[key][left].second)return timemap[key][left].first;
        if(timestamp==timemap[key][right].second)return timemap[key][right].first;
        while(left<=right){
            int mid=(left+right)/2;
            if(timestamp==timemap[key][mid].second)return timemap[key][mid].first;
            if(right-left<=1){
                if(timemap[key][right].second<=timestamp)return timemap[key][right].first;
                if(timemap[key][left].second<=timestamp)return timemap[key][left].first;
                return "";
            }
            if(timestamp<timemap[key][mid].second)right=mid;
            else left=mid;
        }
        return "";
    }
};
