class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right=nums.size()-1;
        if(target<=nums[left])return left;
        if(target>nums[right])return right+1;
        if(target==nums[right])return right;
        while(left<right){
            int mid = (left + right)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]<target){
                left = mid;
            }else right = mid;

            if(right-left==1)return right;
        }
    }
};