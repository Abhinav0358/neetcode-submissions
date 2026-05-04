class Solution{
public:
    int removeElement(vector<int>& nums, int val) {
        int right= nums.size()-1;
        if(nums.size()==0)return 0;
        for(int left=nums.size()-1; left>=0; left--){
            if(nums[right]==val){
                right--;
            }else if(nums[left]==val){
                swap(nums[left],nums[right]);
                right--;
            }
        }
        while(nums[nums.size()-1]==val){
            nums.pop_back();
        }
        return nums.size();
    }
};