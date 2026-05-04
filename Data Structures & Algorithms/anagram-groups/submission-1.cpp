class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mapping;
        vector<vector<string>> answer;
        for(string str: strs){
        string stnd = "00000000000000000000000000";
            for(char c : str){
                stnd[c-'a']++;
            }
            mapping[stnd].push_back(str);
        }
        for(auto& pair: mapping){
            answer.push_back(pair.second);
        }
        return answer;
    }
};
