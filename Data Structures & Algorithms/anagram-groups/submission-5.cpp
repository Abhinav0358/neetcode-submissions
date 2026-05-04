class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mapping;
        vector<vector<string>> answer;
        for(string str: strs){
        string key = str;
        sort(key.begin(),key.end());
            mapping[key].push_back(str);
        }
        for(auto& pair: mapping){
            answer.push_back(pair.second);
        }
        return answer;
    }
};
