class Word{
    public:
        unordered_map<char, Word*> mp;
        bool isend=false;
};
class WordDictionary {
Word * root = new Word();
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        Word * node = root;
        for(char c: word){
            if(node->mp.find(c)!=node->mp.end())node=node->mp[c];
            else{
                node->mp[c]=new Word;
                node=node->mp[c];
            }
        }
        node->isend=true;
    }
    
    bool search(string word) {
        Word * node = root;
        bool ans=false;
        return research(word, node);
        

    }
bool research(string word, Word * node) {
    for(int i=0; i<word.size(); i++){
        char c = word[i];
        if(node->mp.find(c) != node->mp.end()){
            node = node->mp[c];
        }
        else{
            if(c == '.'){
                for(auto const& [key, value] : node->mp){
                    if(research(word.substr(i+1), value)) return true;
                }
                return false; 
            } else {
                return false;
            }
        }
    }
    return node->isend; 
}
};
