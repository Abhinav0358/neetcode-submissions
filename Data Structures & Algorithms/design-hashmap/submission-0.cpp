class MyHashMap {
public:
vector<vector<pair<int,int>>> mp;
    MyHashMap() {
        mp.resize(10);
    }
    
    void put(int key, int value) {
        int ky = key%10;
        for(auto& p : mp[ky]){
            if(p.first==key){
                p.second=value;
                return;
            }
        }
        pair<int,int> p;
        p.first=key;
        p.second=value;
        mp[ky].push_back(p);
    }           
    
    int get(int key) {
        int ky = key%10;
        for(auto& p : mp[ky]){
            if(p.first==key){
                return p.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int ky = key%10;
        for(auto& p : mp[ky]){
            if(p.first==key){
                p=mp[ky][mp[ky].size()-1];
                mp[ky].pop_back();
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */