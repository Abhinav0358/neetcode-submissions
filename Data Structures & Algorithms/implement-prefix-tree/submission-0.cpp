class PrefixTreeNode{
    public:
        unordered_map<char, PrefixTreeNode*> mp;
        bool isend = false;
};
class PrefixTree {
PrefixTreeNode * root = new PrefixTreeNode();
public:
    PrefixTree(){

    }
    
    void insert(string word) {
        PrefixTreeNode * node = root;
        for(char c: word){
            if(node->mp.find(c)!=node->mp.end())node=node->mp[c];
            else{
                node->mp[c]=new PrefixTreeNode();
                node=node->mp[c];
            }
        }
        node->isend=true;
    }
    
    bool search(string word) {
        PrefixTreeNode * node = root;
        for(char c: word){
            if(!(node->mp.find(c)!=node->mp.end()))return false;
            node=node->mp[c];
        }
        return node->isend;
    }
    
    bool startsWith(string prefix) {
        PrefixTreeNode * node = root;
        for(char c: prefix){
            if(!(node->mp[c]))return false;
            node=node->mp[c];
        }
        return true;
    }
};
