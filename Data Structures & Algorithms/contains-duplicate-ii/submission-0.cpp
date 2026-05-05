class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> us;
        // add element
        // check
        // erase

        int left =0;
        int right =0;
        
        while(right<nums.size()){
            if(right-left<k){
                if(us.find(nums[right])!=us.end())return true;
                us.insert(nums[right]);
                right++;
                continue;
            }

            if(us.find(nums[right])!=us.end())return true;
            us.insert(nums[right]);
            us.erase(nums[left]);
            right++;
            left++;
        }
        return false;
    }
};