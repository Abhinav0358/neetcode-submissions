class MyHashSet {
public:
vector<vector<int>>mp;
    MyHashSet() {
        mp.resize(10);
    }
    
    void add(int key) {
        int ky=key%10;
        for(int k : mp[ky]){
            if(k==key)return;
        }
        mp[ky].push_back(key);
    }
    
    void remove(int key) {
        int ky=key%10;
        for(int &k : mp[ky]){
            if(k==key){
                k=mp[ky][mp[ky].size()-1];
                mp[ky].pop_back();
                return;
            }
        }

    }
    
    bool contains(int key) {
        int ky=key%10;
        for(int k : mp[ky]){
            if(k==key){
                return true;
            }
        }
        return false;        
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */