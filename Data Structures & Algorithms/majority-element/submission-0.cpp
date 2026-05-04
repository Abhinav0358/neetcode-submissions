class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mapping;
        for(int k : nums){
            mapping[k]++;
        }
        int max=0;
        int maxelem=0;
        for(auto& p : mapping){
            if(p.second>max){
                max=p.second;
                maxelem=p.first;
            }
        }
        return maxelem;
    }   
};