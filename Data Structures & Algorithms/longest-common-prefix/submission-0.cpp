class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        bool brk=false;
        for(int i=0; i<strs[0].size(); i++){
            char c = strs[0][i];
            for(string str:strs){
                if(i>=str.size()){
                    brk=true;
                    break;
                }
                if(str[i]!=c){
                    brk=true;
                    break;
                }
            }
            if(brk)break;
            ans.push_back(c);
        }
        return ans;
    }
};