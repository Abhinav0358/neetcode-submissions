class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mapping;
        vector<string>keys;
        vector<vector<string>> answer;
        for(string str: strs){
        string stnd = "00000000000000000000000000";
            for(char c : str){
                stnd[c-'a']++;
            }
            if(!mapping.contains(stnd))keys.push_back(stnd);
            mapping[stnd].push_back(str);
        }
        for(string key : keys){
            answer.push_back(mapping[key]);
        }
        return answer;
    }
};
