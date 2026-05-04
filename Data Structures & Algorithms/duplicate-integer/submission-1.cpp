class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int divisor = nums.size();
        unordered_map<int,vector<int>> hashmap;
        for(int i=0; i<nums.size(); i++){
            int remainder = nums[i]%divisor;
            if(hashmap[remainder].size()>0){
                for(int j=0; j<hashmap[remainder].size(); j++){
                    if(hashmap[remainder][j]==nums[i])return true;
                }
            }
            hashmap[remainder].push_back(nums[i]);
        }
        return false;
    }
};