class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size()-1;

        while(left<right){
            int mid = (left + right)/2;
            if(nums[mid]>nums[right])left=mid;
            else right = mid;

            if(right-left==1&&nums[left]>nums[right])return nums[right];
            if(right-left==1&&nums[right]>nums[left])return nums[left];
        }
        return nums[left];
    }
};
