class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left=0;
        int right=0;
        int tr=0;
        int count=0;
        nums[tr]=nums[left];
        tr++;
        count++;
        while(right<nums.size()){
        while(nums[left]==nums[right]){
            right++;
        }
        nums[tr]=nums[right];
        tr++;
        count++;
        left=right;
        }
        count--;
        for(int i=0; i<count; i++){
            nums.pop_back();
        }
        
        return count;

    }
};