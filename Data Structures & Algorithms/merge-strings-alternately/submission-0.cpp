class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        // get lengths
        int l1 = word1.size();
        int l2 = word2.size();
        string s3;
        // take min length, concat both till then
        int small=min(l1,l2);
        for(int i=0; i<small; i++){
            s3.push_back(word1[i]);
            s3.push_back(word2[i]);
        }
        // for the rest of the length just concat the larger string
        if(word2.size()>word1.size()){
            for(int i=small; i<word2.size(); i++){
               s3.push_back(word2[i]);
            }
        }else if(word1.size()>word2.size()){
            for(int i=small; i<word1.size(); i++){
               s3.push_back(word1[i]);
        }
        }
        return s3;        
    }
};