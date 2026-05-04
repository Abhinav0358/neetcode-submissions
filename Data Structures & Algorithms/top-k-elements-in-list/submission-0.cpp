class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hashmap;
        for(int i=0; i<nums.size(); i++){
            hashmap[nums[i]]++;
        }
        vector<pair<int,int>> pairs;
        for(auto &pr: hashmap){
            pairs.push_back(pr);
        }
        sort(pairs.begin(),pairs.end(), [](const auto&a, const auto &b){
         return a.second>b.second;   
        });

        vector<int> result;
        for(int i=0; i<k; i++){
            result.push_back(pairs[i].first);
        }
        return result;

    }
};
