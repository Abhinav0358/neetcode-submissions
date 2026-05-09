class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        if(nums[left]==target)return left;
        if(nums[right]==target)return right;
        
        while(right-left>1){
        int mid = (left + right)/2;
        if(nums[mid]==target)return mid;
        else if(nums[mid]<target){
            left=mid;
        }else right=mid;
        }
        
        return -1;

    }
};
