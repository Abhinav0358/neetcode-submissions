class TimeMap {
unordered_map<string,vector<pair<string,int>>> timemap;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timemap[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        for(int i=timemap[key].size()-1; i>=0; i--){
            if(timemap[key][i].second<=timestamp)return timemap[key][i].first;
        }
        return "";
    }
};
