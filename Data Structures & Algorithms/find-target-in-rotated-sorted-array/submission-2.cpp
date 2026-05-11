class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left =0;
        int right = nums.size()-1;
        if(nums[left]==target)return left;
        if(nums[right]==target)return right;
        while(left<right){
            int mid = (left + right)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]<nums[right]){
                if(nums[mid]<target&&target<nums[right])left=mid;
                else right = mid;
            }else if(nums[mid]>nums[right]){
                if(nums[mid]>target&&target>nums[left])right=mid;
                else left = mid;
            }

            if(right-left==1)return -1;
        }
        return -1;
    }
};
