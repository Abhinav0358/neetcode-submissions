class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        part(nums,-1,nums.size()-1);
        return nums;
    }
    void part(vector<int>& nums, int startindex, int endindex){
        if(startindex>=endindex)return;
        int boundary=startindex;
        for(int i=startindex+1; i<=endindex; i++){
            if(nums[endindex]>=nums[i]){
                boundary+=1;
                swap(nums[boundary],nums[i]);
            }
        }
        part(nums,boundary,endindex);
        part(nums,startindex,boundary-1);
    }
};